#Hello
#This is the Api code to get location.
import urllib.error, urllib.request, urllib.parse
import json
#give the target api url to open 
target = '' 
local = input('Enter location: ')
url = target + urllib.parse.urlencode({'address': local, 'key' : 42})

print('Retriving', url)
data = urllib.request.urlopen(url).read()
print('Retrived', len(data), 'characters')
js = json.loads(data)
print(json.dumps(js, indent = 4)) 
print('Place id', js['results'][0]['place_id'])
