string=str(input("Enter the string you want to check."))
string=string.casefold()
rev=reversed(string)

if(list(string)==list(rev)):
    print("The string that you have entered is a palindrome")
else:
    print("The string that you have entered is not a palindrome")