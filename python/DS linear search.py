a=int(input("Enter the size of the array"))
print("Enter the elements of the array")
arr=[]
for i in range(a):
    arr.append(int(input())).split()

n=int(input("Enter the element you want to search"))
for i in arr:
    if i==n:
        print("The element is present at position : ",i+1)
        break
else:
    print("The element is not present")
    
