<!DOCTYPE html>
<html lang="pt-br">
    <head>
        <meta charset="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
        <title>pegar mime type de arquivo usando js</title>
    </head>
    <body>
        <input type="file" onchange="processa()" />


        <script>
            function getType( fileHeader ) 
            {
                console.log(fileHeader)
                let type = 'unknown'
                switch (fileHeader) 
                {
                    case "89504e47":
				        type = "image/png"
                    break
                    
                    case "47494638":
                        type = "image/gif"
                    break

                    case "ffd8ffe0":
                        type = "jpg"
                    break

                    case "ffd8ffe1":
                        type = "jpg"
                    break

                    case "ffd8ffdb":
                        type = "jpg"
                    break

                    case "ffd8ffe2":
                        type = "image/jpeg"
                    break

                    case "25504446":
                        type = "pdf"
                    break

                    case "7b5c7274":
                        type = "rtf"
                    break

                    case "504b0304":
                        type = "zip archive (Office)"
                    break

                    case "504b0506":
                        type = "zip archive empty"
                    break

                    case "504b0708":
                        type = "zip archive spanned"
                    break

                    case "49492a00":
                        type = "TIF (little endian format)"
                    break

                    case "4d4d002a":
                        type = "TIF (big endian format)"
                    break

                    case "d0cf11e0":
                        type = "Old Office Format"
                    break

                    default:
                        type = "Unsupported"
                    break
                }
                return type
            }

            function getMimeType( file )
            {
                return new Promise((resolve, reject) => {
                    const reader = new FileReader()
                    reader.readAsArrayBuffer(file)

                    reader.onload  = () => {
                        let arr    = (new Uint8Array(reader.result)).subarray(0, 4)
                        let header = ''
                        for (let i = 0; i < arr.length; i++)
                        {
                            header += arr[i].toString(16)
                        }   
                        resolve( getType( header ) )
                    }
                    reader.onerror = _ => reject(_)
                })
            }

            function processa()
            {
                getMimeType( document.querySelector('input').files[0] ).then(console.log)
            }
        </script>
    </body>
</html>
