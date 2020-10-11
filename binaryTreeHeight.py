#!/usr/local/bin/python3.6
#A simple program to find height of binary tree using nodes as input
import math
def green(str):
	return ("\x1B[32m"+str)
def reset():
	return ("\x1B[0m")

try:
	n=int(input("Enter number of nodes to find binary tree height: "))
	h=math.sqrt(n)
	h2=float(int(h))
	if(h>h2):
		print(green("Height = ")+reset(),h2+1)
	else:
		print("Height = ",h2)
except ValueError:
	print("Oops!  That was no valid number.  Try again...")
