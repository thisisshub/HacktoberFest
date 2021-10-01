string = input("Please enter your own String : ")
flag = 0
length = len(string)

for i in range(length):
    if(string[i] != string[length - i - 1]):
        flag = 1
        break

if(flag == 0):
   print("This is a Palindrome String")

else:
   print("This is Not a Palindrome String")
