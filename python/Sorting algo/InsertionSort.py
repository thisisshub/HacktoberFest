def InsertionSort(array):
	for i in range(1,len(array)):
		current = array[i]
		j = i-1
		while(j >= 0 and current < array[j]):
			array[j+1] = array[j]
			j -= 1
		array[j+1] = current
array = [32,33,1,0,23,98,-19,15,7,-52,76]
print("Before sort: ")
print(*array,sep=', ')
print("After sort: ")
InsertionSort(array)
print(*array,sep=', ')