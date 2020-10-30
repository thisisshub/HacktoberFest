

import sys
import PyPDF2

try:
	file_name = sys.argv[1]  # to give file name on which you want to do watermark operation
	watermark = sys.argv[2]  # to give watermark file name which contain watermark
	output_file = sys.argv[3] # to give name to your output file 
	file_name = PyPDF2.PdfFileReader(open(file_name, 'rb'))
	watermark = PyPDF2.PdfFileReader(open(watermark, 'rb'))
	output = PyPDF2.PdfFileWriter()
	for i in range(file_name.getNumPages()):
		page = file_name.getPage(i)
		page.mergePage(watermark.getPage(0))
		output.addPage(page)

		with open(output_file, 'wb') as file:
			output.write(file)
	print("It's done")
	print('----------')
	print('Watermarked pdf is ready')
except FileNotFoundError as err:
	print('hey, check for your file name or location')
	print('Does it really exist? Check for it.')

