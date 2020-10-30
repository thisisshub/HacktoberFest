import random

response = 0
list = []

while response == 0:
  new_name = input('Insert a name: ')
  list.append(new_name)
  answer = input('Want to put another name? type 1: ')
  if answer == '1':
    response = 1

print(random.choice(list))