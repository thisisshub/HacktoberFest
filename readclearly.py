import bs4
import requests
import time
from io import StringIO
import sys

msg = input("Please enter URL:")


old_stdout = sys.stdout
new_stdout = StringIO()
sys.stdout = new_stdout

try:
    if "https://" in msg:
        res = requests.get(msg)
        data = bs4.BeautifulSoup(res.text, "lxml")
        datatxt = data.select("p")
        def gettext():
            lenght = len(datatxt)
            num = 0
            while num < lenght:
                text = datatxt[num].getText()
        
                datatext = str(text)
                numberword = datatext.count(" ")
                num +=1
                    
                if numberword > 3:
                    print(datatext, "\n")
        gettext()
    else:
        https = "https://"
        message = https + msg
            
        res = requests.get(message)
        data = bs4.BeautifulSoup(res.text, "lxml")
        datatxt = data.select("p")
        def gettext():
            lenght = len(datatxt)
            num = 0
            while num < lenght:
                text = datatxt[num].getText()
        
                datatext = str(text)
                numberword = datatext.count(" ")
                num +=1
                    
                if numberword > 3:
                    print(datatext, "\n")
        gettext()
    
except:
    print("The URL adress you entered is invalid or URL adress seems to be unavailable now")

output = new_stdout.getvalue()

sys.stdout = old_stdout

print(output)