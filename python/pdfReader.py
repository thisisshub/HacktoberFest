import pyttsx3
import PyPDF2

book = open('sample.pdf','rb')
pdfReader = PyPDF2.PdfFileReader(book)
pages = pdfReader.numPages
print(pages)

speaker = pyttsx3.init()
page = pdfReader.getPage(0)
text = page.extractText()
speaker.say(text)
speaker.runAndWait()