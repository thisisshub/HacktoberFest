#Find GST Usign Python
#By Programmers0_0;

op = int(input("Enter Original Price:"))
gst = int(input("Enter GST:"))

cal = op * gst / 100

total = op + cal
print("Total:", total)