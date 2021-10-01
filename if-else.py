#Holla!!

p = 2000
m = int(input("Enter m"))

if m<p:
    print("You cannot buy a game")
elif m==p:
    print("You can buy some games")
else:
    print("You can buy premium games")

# Short-Hand If Else
a = int(input())
b = int(input())
print("A is greater") if a>b else print ("B is greater")
