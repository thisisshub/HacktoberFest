def palindrome(s):
    return s == s[::-1]
s = input("enter input:")
ans = palindrome(s)
if ans:
    print(s,"is a palindrome")
else:
    print(s,"is not a palindrome")
