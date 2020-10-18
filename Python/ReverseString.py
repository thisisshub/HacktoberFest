def RevS(a):
	a=str(a)
	for i in range(len(a)-1,-1,-1):
		print(a[i],end="")
	print()
s=input()
RevS(s)