# Armstrong number :- Example for a three digit no. The sum of cubes of digits of
# number is equal to the number itself.
n = int(input())
s = 0
order = len(str(n))
temp = n
while temp > 0:
   digit = temp % 10
   s += digit ** order
   temp //= 10
if n == s:
   print(n,"is an ARMSTRONG NUMBER")
else:
   print(n,"is NOT AN ARMSTRONG NUMBER")
