import random
import string

password_length = int(input("Enter the length of your password you do wanna create "))

password_characters = string.ascii_letters+string.digits+string.punctuation

password=[]

for i in range(password_length):
    password.append(random.choice(password_characters))
print(''.join(password))