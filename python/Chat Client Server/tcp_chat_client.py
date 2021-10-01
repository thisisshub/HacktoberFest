#!/usr/bin/python
from socket import *
import select
import sys
serverPort = 21460
serverName = '127.0.0.1'
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((serverName, serverPort))
while True:
		socket_list = [sys.stdin, clientSocket]
		readable, writeable, errored = select.select(socket_list, [], [])
		for sockt in readable:
			if sockt == clientSocket:
				message = sockt.recv(2048)
				print(message)
			else:
				message = sys.stdin.readline()
				clientSocket.send(message)
				sys.stdout.write("<You> :")
				sys.stdout.write(message)
				sys.stdout.flush()
clientSocket.close()