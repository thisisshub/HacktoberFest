import socket               # Import socket module

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
host = socket.gethostname() # Get local machine name
port = 12345                # Reserve a port for your service.
s.bind((host, port))        # Bind to the port

#s.listen(5)                 # Now wait for client connection.
#while True:
#str, addr = s.recvfrom(1024)     # Establish connection with client.
#print ('Got connection from', addr)

while (True):
	str,addr =s.recvfrom(1024)
	print(str," received from ", addr)
	if str==b"Bye":
		print("Client breaking connection")
	strr = input("Enter the msg : ")
	s.sendto(strr.encode(), (addr))
	print ("Receiving")
