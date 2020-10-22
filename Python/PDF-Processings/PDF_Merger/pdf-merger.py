import PyPDF2
import sys

inputs = sys.argv[1:]

def pdf_list(names):
	merger = PyPDF2.PdfFileMerger()
	for pdf in names:
		merger.append(pdf)
	merger.write('merged.pdf')

pdf_list(inputs)