# Input email from user
inputEmail = str(input("Please Input Your Email : "))

# slice the domain from email
slicing = inputEmail.split('@')[0]

# Printing username
print("your username is " + slicing) 