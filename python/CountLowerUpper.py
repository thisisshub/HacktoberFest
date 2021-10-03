print('Count lowercase and uppercase')

s = input()
clower = 0
cupper = 0

for i in s:
    if i.islower() == True:
        clower += 1
    elif i.isupper() == True:
        cupper += 1
        
print(clower)
print(cupper)