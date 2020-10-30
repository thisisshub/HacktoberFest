def binary_incr(base,incr):			# (base: Binary, incr: Decimal)
	i=1
	lst=list(str(base))
	while incr!=0:
		try:
			temp=int((int(lst[-i])+incr)%2)
		except:
			lst.insert(0,0)
			temp=int((int(lst[-i])+incr)%2)
		incr=int((int(lst[-i])+incr)/2)
		lst[-i]=str(temp)
		i+=1
	return int(str().join(lst))			#* 'int()' for Output restrict starting '0'
print(binary_incr(int(input('Enter 1st Decimal Number: ')),int(input('Enter 2nd Decimal Number: '))))
