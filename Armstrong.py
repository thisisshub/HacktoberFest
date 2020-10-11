# Armstrong number :- Example for a three digit no. The sum of cubes of digits of
# number is equal to the number itself.
n = int(input())
s = 0
for i in str(n):
    s += int(i)**3
if s == n:
    print("ARMSTRONG NUMBER")
else:
    print("NOT A ARMSTRONG NUMBER")