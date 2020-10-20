# a='hello;
# a[::-1] --> 'olleh'

def RevS(a):
	a=str(a)
	for i in a[::-1]: # efficient way in python
		print(i,end="")
	print()
s=input()
RevS(s)
