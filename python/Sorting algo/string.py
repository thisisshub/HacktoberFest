# Python program to implement Selection Sort for
# array of strings

# Function defined for sorting the array of strings
def Selection(arr,n):

	# One by one move boundary of unsorted subarray
	for i in range(n):
		min_index = i
		min_str = arr[i]
		
		# Find the minimum element in unsorted subarray
		for j in range(i+1,n):
			
			# If min_str is greater than arr[j]
			if min_str>arr[j]:
				
				# Make arr[j] as min_str and update min_index as j
				min_str = arr[j]
				min_index = j
				
		# Swap the found minimum element with the first element	
		if min_index != i:
			
			# Store the first element in temp
			temp = arr[i]
			
			# Place the min element at the first position
			arr[i] = arr[min_index]
			
			# place the element in temp at min_index
			arr[min_index] = temp
	
	# Return the sorted array
	return arr

arr = ["GeeksforGeeks", "Practice.GeeksforGeeks", "GeeksQuiz"]

print("Given array is")
for i in range(len(arr)):
	print(i,":",arr[i])

print("\nSorted array is")
for i in range(len(Selection(arr,len(arr)))):
	print(i,":",Selection(arr,len(arr))[i])
			
# This code is contributed by Manish KC
# profile: mkumarchaudhary06
