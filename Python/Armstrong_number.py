# 153 = 1*1*1 + 5*5*5 + 3*3*3
# Enter a three-digit integer: 371
# 371 is an Armstrong number.

n=371

m=sum([int(i)**3 for i in str(n) ])
if n==m:
	print("Its Armstrong number ")
else:
	print("Its not Armstrong number")
