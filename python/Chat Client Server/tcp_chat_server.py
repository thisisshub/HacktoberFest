#!/usr/bin/python
from socket import *
from thread import *
import select 
serverPort = 21460
serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind(('', serverPort))
serverSocket.listen(100)
client_list = []
exit = 'EXIT'
print('Chat Server Started')

def create_thread(connectionSocket, addr): 
	connectionSocket.send("WELCOME TO THE CHAT\n")
	connectionSocket.send("TYPE \"EXIT\" TO LEAVE CHAT")
	while True: 
			try: 
				message1 = connectionSocket.recv(2048)
				message = message1[:-1]
				if message == exit:
					remov(connectionSocket)
					break
				print("< " + addr[0] + " > : " + message)
				message_to_send =  "< " + addr[0] + " > : " + message
				send_message(connectionSocket, message_to_send) 
			except: 
				continue

def remov(connectionSocket):
	if connectionSocket in client_list: 
		client_list.remove(connectionSocket)
		message = "< " +  addr[0] + " > : " + "Left the Chat"
		print("< " + addr[0] + " > : " + "Disconnected")
		send_message('', message)

def send_message(connection, message): 
	for client in client_list:
    	 if client != connection:
        	try : 
        		client.send(message) 
        	except :
        		client.close() 
        		client_list.remove(client)


while True:
	connectionSocket, addr = serverSocket.accept()
	client_list.append(connectionSocket)
	print("< " +  addr[0] + " > : " + "Connected")
	message = "< " +  addr[0] + " > : " + "Joined the chat"
	send_message(connectionSocket, message)
	start_new_thread(create_thread,(connectionSocket,addr))
connectionSocket.close()
server.close()
