# Python Program to find LCM of Two Numbers

a = float(input(" Please Enter the First Value a: "))
b = float(input(" Please Enter the Second Value b: "))

if(a > b):
    maximum = a
else:
    maximum = b

while(True):
    if(maximum % a == 0 and maximum % b == 0):
        print("\nLCM of {0} and {1} = {2}".format(a, b, maximum))
        break
    maximum = maximum + 1
