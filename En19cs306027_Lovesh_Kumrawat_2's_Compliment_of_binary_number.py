# Program to find the 2's Compliment of given binary number
def _1s_complt(base):			# (base: Binary)

	_1s=((base.replace('0','_')).replace('1','0')).replace('_','1')			#* 1's Compliment
	return _2s_complt(_1s,1)

def _2s_complt(base,incr):
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
	return str().join(lst)

print(_1s_complt(input('Enter the Binary Number: ')))
