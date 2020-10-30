n=int(input("enter a number="))
i=1
while i<=n:
  if i&1 :
    print(i,"is odd")
  else: 
    print(i,"is even")
    i=i+1
print("loop ends")
