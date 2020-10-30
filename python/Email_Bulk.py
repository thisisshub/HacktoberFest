import smtplib
import csv

from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email import encoders

def Users(email):
  subject = 'Subject'
  msg = MIMEMultipart()
  email_user = 'email_address' #CHANGE email_address to FROM EMAIL ADDRESS
  email_password = 'password' #CHANGE password to FROM PASSWORD
  email_send = email # DO NOT MAKE CHANGES TO THIS
  msg['From'] = email_user
  # converting list of recipients into comma separated string
  msg['To'] = ", ".join(email_send)
  msg['Subject'] = subject
  body = """
  <h1>Message</h1>
        """
  msg.attach(MIMEText(body, 'html'))
  text = msg.as_string()
  server = smtplib.SMTP('smtp.gmail.com',587)
  server.starttls()
  server.login(email_user,email_password)
  server.sendmail(email_user,email_send,text)
  server.quit()

results = []
with open('CSV_File_Name.csv', newline='') as inputfile: # CHANGE CSV FILE NAME
    for row in csv.reader(inputfile):
        results.append(row[0])
for i in range(len(results)):
    Users(list(results[i].split(" ")))
