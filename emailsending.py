#This is a python code for sending email messages to different mailing address
#Program by : Sayantan Bose
import smtplib as s
ob=s.SMTP("smtp.gmail.com",587)
ob.starttls()
ob.login("your gmail address","your password")
subject="Who is the current president of India"
body="Hi Sayantanbose,Who is the current president of India?Answer this question and earn Rs.0.25"
message="Subject: {}\n\n{}".format(subject,body)
listOfAddress=["any mail id"]
ob.sendmail("your own mail id",listOfAddress,message)
ob.quit()
print("Send successfully..")