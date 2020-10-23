""" Python Script to find primes numbers upto a specified limit """

# Write your code from here
num = int(input("enter a number:"))
if num > 1:
    for i in range(2,num):
        if (num%i)==0:
            print(num,"is not a prime number")
            break
        else :
            print(num,"is a prime number")
else:
    print(num,"is not a prime number")

    