## How to run
1. Clone the repo
   ```
   git clone git@github.com:GDSC-RCCIIT/General-Purpose-Scripts.git
   ```
2. Navigate to `QR Code Generator` directory
   ```
   cd General-Purpose-Scripts/scripts/QR\ Code\ Generator
   ```
3. Install the script requirements
   ```
   pip3 install -r requirements.txt
   ```
4. Run the script to generate QR Code for your link
   ```
   python3 qr_code_gen.py --link <link> --path <path/to/generated_file>
   ```
   Or,
   ```
   python3 qr_code_gen.py -l <link> -p <path/to/generated_file>
   ```
Replace `<link>` with the website URL.
Replace `<path/to/generated_file>` with the path to the directory where you want to save the files.

The QR Code (in .png and .svg) will be generated in the `QR Code Generator` directory.

### Note
The `-p` (`--path`) is optional. If not provided, the files will be saved in the `QR Code Generator` directory.

### Screenshot
![CLI screen grab](https://imgur.com/cKRFSsW.png)