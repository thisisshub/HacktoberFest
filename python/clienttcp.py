import socket               # Import socket module

s = socket.socket()         # Create a socket object
host = socket.gethostname() # Get local machine name
port = 12345                # Reserve a port for your service.

s.connect((host, port))
while(True):
	str = input("Enter your msg : ")
	#b=bytes(str1,'utf-8')
	s.send(str.encode())
	print("Receiving........")
	str= s.recv(1024)
	print(str)
	if str==b"Bye":
		print("Client breaking connection.......")
		break
s.send(b"bye")
s.close()
