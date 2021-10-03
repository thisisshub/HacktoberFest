import requests
from bs4 import BeautifulSoup
import matplotlib.pyplot as plt
import matplotlib.dates as dt
import datetime

plt.style.use('dark_background')

fig, ax = plt.subplots()
ax.xaxis_date()

urls = ["https://www.imdb.com/title/tt0115147/episodes?year=2020", "https://www.imdb.com/title/tt3513388/episodes?year=2020",
        "https://www.imdb.com/title/tt3530232/episodes?year=2020", "https://www.imdb.com/title/tt3444938/episodes?year=2020&ref_=tt_eps_yr_2020","https://www.imdb.com/title/tt3444938/episodes?year=2020&ref_=tt_eps_yr_2020","https://www.imdb.com/title/tt0320037/episodes?year=2020&ref_=tt_eps_yr_2020","https://www.imdb.com/title/tt4280606/episodes?year=2020&ref_=tt_eps_yr_2020"]
colors = ["red", "orange", "blue", "violet","limegreen","darkorange","ivory"]
legends = ["The Daily Show", "Late Night",
           "Last Week Tonight", "The Tonight Show","The Tonight Show Starring Jimmy Fallon","Conan","Jimmy Kimmel Live!","The Late Late Show with James Corden"]
for index, url in enumerate(urls):
    r = requests.get(url=url)
    soup = BeautifulSoup(r.text, 'html.parser')

    value = soup.findAll("span", {"class": "ipl-rating-star__rating"})
    value = [float(v.text) for v in value if "." in v.text]

    date = soup.findAll("div", {"class": "airdate"})
    date = ["".join("".join(d.text.split()).split("."))
            for d in date][:len(value)]
    date = [datetime.datetime.strptime(f"{d}", '%d%b%Y') for d in date]
    date = dt.date2num(date)
    for i, d in enumerate(date[1:]):
        if d > date[i+1]:
            d = date[i+1]

    ax.plot(date, value, color=colors[index], label=legends[index])

ax.set_xlabel('Date of airing')
ax.set_ylabel('IMDb rating')
ax.set_title(
    "Were the ratings of late night TV affected by the hosts filming from their home?")


plt.legend()
plt.show()
