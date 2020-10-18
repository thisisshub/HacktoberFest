# Sorting an array using Selection Sort Technique
from array import *


def selection_sort(input_list):

    for idx in range(len(input_list)):

        min_idx = idx
        for j in range( idx +1, len(input_list)):
            if input_list[min_idx] > input_list[j]:
                min_idx = j
# Swap the minimum value with the compared value

        input_list[idx], input_list[min_idx] = input_list[min_idx], input_list[idx]


# Create the array
ar = array('i',[])

n = int(input("Enter the number of elements : "))
print("Enter the values:")

for i in range(n):
    ar.append(int(input()))
print("Original Array :",ar)

selection_sort(ar)
print(ar)
