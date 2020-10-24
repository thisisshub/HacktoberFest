fun main(args: Array<String>) {
    
    //regex
    val month = "(JAN|FEB|MAR|APR|MAY|JUN|JUL|AUG|SEP|OCT|NOV|DEC)"
	fun getPattern(): String = """\d{2}\h$month\h\d{4}"""
    val regex = Regex(getPattern())
    val str ="12 DEC 1996"
    val flag = regex.containsMatchIn(str)
    if (flag)
    	println("{$str} is true!")
    else
    	println("{$str} is wrong!")
    
    //null
    val listWithNulls: List<String?> = listOf("A", null, "B", "ERROR 404", null)
	for (item in listWithNulls) {
     	item?.let  {println(it)}  ?: println("element is empty") 
	}
}