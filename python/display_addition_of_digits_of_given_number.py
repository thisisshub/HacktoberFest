#python program to display sum of digits of given number
n=int(input("enter an integer number"))
sum=0
temp=n
while n!=0:
    r=n%10
    sum=sum+r
    n=n//10
print("The sum of",temp,"is",sum)
