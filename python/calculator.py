while True:
    x = (input("enter first digit"))
    try:
        a = float(x)
    except:
        print("error")
    continue



y = input("enter operator")

z = (input("enter other digit"))
try:
    b = float(z)
except:
    print("error")

def calculate(y):

    if y == '+':
        print(a + b)

    elif y == '-':
        print(a - b)


    elif y == '*':
        print(a * b)


    elif y == '/':
        print(a / b)

    else:
        print('error')

calculate(y)
