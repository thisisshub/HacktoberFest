#program for checking an integer is palindrome or not
'''
a=int(input("Enter number of string you wanted to run:-"))
list1=[]
for i in range(a):
    a=str(input())
    list1.append(a)
print(list1)
for index,items in enumerate(list1):
        if items==items[::-1]:
            print (items,",yes It is palindrome")
        else:
            print(items,",No, it is not palindrome")
'''
#program to find next palindrome of given integer n;
def palindrome(n):
    n+=1
    if(n<10):
        a=10-n
        b=n+a+1
        while not is_palindrome(b):
         b+=1
        return b
    else:
     while not is_palindrome(n):
        n+=1
    return n
def is_palindrome(n):
    return str(n)==str(n)[::-1]

if __name__ == '__main__':
 try:
  n=int(input("Enter Numbers you want to print "))
  numbers=[]
  list=[]
  for i in range(n):
    number=int(input("Enter number "))
    numbers.append(number)
  for i in range(n):
   print(f"Next Palindrome of {numbers[i]} is {palindrome(numbers[i])}" )
   list.append(palindrome(numbers[i]))
  print(list)

 except Exception as e:
     print(e)
