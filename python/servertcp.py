import socket               # Import socket module

s = socket.socket()         # Create a socket object
host = socket.gethostname() # Get local machine name
port = 12345                # Reserve a port for your service.
s.bind((host, port))        # Bind to the port

s.listen(5)                 # Now wait for client connection.
#while True:
c, addr = s.accept()     # Establish connection with client.
print ('Got connection from', addr)

while (True):
	str=c.recv(1024)
	print(str)
	if str==b"Bye":
		print("Client breaking connection")
		#break
	strr = input("Enter the msg : ")
	c.send(strr.encode())
