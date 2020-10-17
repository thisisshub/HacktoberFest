x = None
lst = list()
while True:
    x = input('enter a no')
    if x == 'done':
        break
    else:
        try:
            lst.append(int(x))
        except:
            print('Invalid input')
            continue

print('Maximum is',max(lst))
print('Minimum is', min(lst))
