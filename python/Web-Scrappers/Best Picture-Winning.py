import requests                 # Simpler HTTP requests 
from bs4 import BeautifulSoup   # Python package for pulling data out of HTML and XML files
import pandas as pd             # Python package for data manipulation and analysis
import re                       # regular expressions

url = 'https://www.imdb.com/search/title/?count=100&groups=oscar_best_picture_winners&sort=year%2Cdesc&ref_=nv_ch_osc'             
url_text = requests.get(url).text                    # Get the session text for the link
url_soup = BeautifulSoup(url_text, 'html.parser')   # Get data from the HTML

def cleanhtml(raw_html):
  cleanr = re.compile('<.*?>|&([a-z0-9]+|#[0-9]{1,6}|#x[0-9a-f]{1,6});')
  cleantext = re.sub(cleanr, '', str(raw_html))
  return cleantext.strip()

rows = url_soup.find_all("div", class_="lister-item mode-advanced")

movie_title = url_soup.find_all("h3", class_ ="lister-item-header")
movie_info = url_soup.find_all("div", class_ ="lister-item-content")
rating_bar = url_soup.find_all("div", class_="ratings-bar")
dataframe_columns = [ 'Movie_Title', 'year', 'certificate' , 'runtime' , 'genre' , 'Imdb Rating', 'MetaScore']
dataframe = pd.DataFrame(columns=dataframe_columns)
for f, b, i ,j in zip(movie_title, movie_info, rating_bar, range(0,len(movie_info))):
    dataframe.at[j,'Movie_Title'] = f.find('a', href=True).text
    dataframe.at[j,'year'] = f.find('span', class_="lister-item-year text-muted unbold").text
    dataframe.at[j,'certificate'] = cleanhtml(b.find("span", {"class":"certificate"}))
    dataframe.at[j,'runtime'] = cleanhtml(b.find('span', class_="runtime"))
    dataframe.at[j,'genre'] = cleanhtml(b.find('span', class_="genre"))
    dataframe.at[j,'Imdb Rating'] = cleanhtml(i.find('div', class_="inline-block ratings-imdb-rating"))
    dataframe.at[j,'MetaScore'] = cleanhtml(i.find('span', class_="metascore"))

print(dataframe.head(10))




    
    






