# Python3 Optimized implementation 
# of Bubble sort 


'''
def bubbleSort(arr): 
	n = len(arr) 

 
	for i in range(n): 
		swapped = False

		
		for j in range(0, n-i-1): 

			
			if arr[j] > arr[j+1] : 
				arr[j], arr[j+1] = arr[j+1], arr[j] 
				swapped = True

	
		if swapped == False: 
			break
		
# Driver code to test above 
arr = [64, 34, 25, 12, 22, 11, 90] 

bubbleSort(arr) 

print ("Sorted array :") 
for i in range(len(arr)): 
	print ("%d" %arr[i],end=" ") 
'''
def bubble_sort(li):
    l = len(li)
    tmp = None
    sorted_l = sorted(li)
    while (li != sorted_l):
        for ele in range(0,l-1):
            if li[ele] > li[ele+1]:
                tmp = li[ele+1]
                li[ele+1] = li [ele]
                li[ele] = tmp
    return li

