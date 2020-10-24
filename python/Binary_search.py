def binarysearch(lst , x):
    l = 0
    u = len(lst)-1
    mid = 0
    while l<=u:
        mid = (l+u)//2
        if lst[mid] == x:
            return mid
        elif lst[mid] < x:
            l = mid+1
        else: #if lst[mid] > x
            u = mid-1
lst=[]
n=int(input("enter number of elements:"))
for i in range(n):
    ele=int(input("enter elements:"))
    lst.append(ele)
x = int(input("enter search element:"))
print("element present at index:",binarysearch(lst, x))
