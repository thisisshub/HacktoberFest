import requests
from bs4 import BeautifulSoup
import ssl
import csv
from csv import writer

#ignore SSL certificate errors
ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE


url = "https://www.linkedin.com/jobs/search/?keywords=Software%20Engineer%20Intern"
html = requests.get(url)

# using str to turn into html source string 
soup = BeautifulSoup(str(html.content), 'html.parser')
# print(soup.prettify())

filename = "scrape.csv"
csv_writer = csv.writer(open(filename, 'w'))

results = soup.find(class_='jobs-search__results-list')
print(soup.results)

with open(filename, 'w') as csv_file:
  csv_writer = writer(csv_file)
  headers = ['Title', 'Location', 'Company']
  csv_writer.writerow(headers)

  for job_elem in results:

    title = job_elem.find('span', class_='screen-reader-text').get_text()

    location = job_elem.find('span', class_='job-result-card__location').get_text()

    company = job_elem.find('h4', class_='result-card__subtitle').get_text()


    csv_writer.writerow([title, location, company])