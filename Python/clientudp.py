import socket               # Import socket module

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
host = socket.gethostname() # Get local machine name
port = 12345                # Reserve a port for your service.

s.connect((host, port))
while(True):
	str = input("Enter your msg : ")
	#b=bytes(str1,'utf-8')
	s.sendto(str.encode(), (host,port))
	print("Receiving........")
	str= s.recvfrom(1024)
	print(str)
	if str==b"Bye":
		print("Client breaking connection.......")
		break
s.sendto(b"bye", (host,port))
s.close()
