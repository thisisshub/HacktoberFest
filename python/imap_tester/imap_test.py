from imbox import Imbox
import html2text
import requests
import json
import time

with open('config.json') as config_file:
    data = json.load(config_file)

def get_mail(content):
  html = (str(content))

  text_maker = html2text.HTML2Text()
  text_maker.ignore_links = True
  text_maker.bypass_tables = False
  

  text = text_maker.handle(html)

  # Slice everything that comes between html': and ]}
  start = "html':"
  end = "]}"
  mail_content = text[text.find(start) + len(start):text.rfind(end)]
  
  # Normalize content, removing unknown chars if necessary
  # mail_content = mail_content.replace("['","")
  # mail_content = mail_content.replace('\\xa0', ' ')
  # mail_content = mail_content.replace("'","")
  # mail_content = mail_content.replace("\\r\\n","")
  
  return text
  
with Imbox('imap.gmail.com',
        username = data['mail_username'],
        password = data['mail_password'],
        ssl = True,
        ssl_context = None,
        starttls = False) as imbox:

    fetch_mail_type = imbox.messages(sent_from = data['mail_from_username'])

    # Get all folders
    #status, folders_with_additional_info = imbox.folders()

    # Gets all messages from the inbox
    #all_inbox_messages = imbox.messages()

    for uid, message in fetch_mail_type:
    # Every message is an object with the following keys

        origin = message.sent_from
        receiver = message.sent_to
        subject = message.subject
        headers = message.headers
        message_id = message.message_id
        message_date = message.date
        content = message.body
        message_attachments = message.attachments

        #result = get_mail(content)
        print("Assunto: " + subject)