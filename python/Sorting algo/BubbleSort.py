# Sorting an array using Bubble Sort Technique

from array import *

# Create the array
ar = array('i',[])

n = int(input("Enter the number of elements : "))
print("Enter the values:")

for i in range(n):
    ar.append(int(input()))
    
print("Original Array :",ar)

# Bubble Sort
flag = False

for i in range(n-1):
    for j in range(n-1-i):
        if ar[j]>ar[j+1]:
            t = ar[j]
            ar[j] = ar[j+1]
            ar[j+1] = t
            flag = True
    if flag == False:
        break
    else:
        flag = False

print("Sorted array:",ar)
    