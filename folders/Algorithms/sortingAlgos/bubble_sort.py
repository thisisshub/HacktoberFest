def bSort(ar): 
	n = len(ar) 

	for i in range(n-1):  
		for j in range(0, n-i-1): 

			if ar[j] > ar[j+1] : 
				ar[j], ar[j+1] = ar[j+1], ar[j] 

arr = [64, 34, 25, 12, 22, 11, 90] 

bSort(ar) 

print ("Sorted array is:") 
for i in range(len(arr)): 
	print ("%d" %arr[i])
