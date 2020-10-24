# Program to Extract the all 'Tags', 'URL', 'Contents' & 'Attrs' given on a Web Page.
from urllib.request import urlopen
from bs4 import BeautifulSoup

url ='http://py4e-data.dr-chuck.net/comments_42.html'
html=urlopen(url).read()
soup=BeautifulSoup(html,'html.parser')
tags=soup('span')

for tag in tags:
	print('TAG:',tag)
	print('URL:',tag.get('href',None))
	print('Contents:',tag.contents)
	print('Attrs:',tag.attrs)
