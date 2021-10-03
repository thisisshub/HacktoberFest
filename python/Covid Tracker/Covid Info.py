import requests
from bs4 import BeautifulSoup

url = 'https://www.worldometers.info/coronavirus'
page = requests.get(url)
soup = BeautifulSoup(page.text, 'html.parser')
x=soup.find_all('div',class_="maincounter-number")

total_case=str(x[0].text).strip()
total_death=str(x[1].text).strip()
total_recover=str(x[2].text).strip()

print("Total Case:",total_case)
print("Total Death:",total_death)
print("Total Recover:",total_recover)
