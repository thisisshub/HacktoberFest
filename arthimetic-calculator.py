while True:
  try:
    x = int(input("What is the first number? "))
    y = int(input("What is the second number? "))
    print("The sum is: ", x+y)
    print("The difference is: ", x-y)
    print("The product is: ", x*y)
    print("The result after division is: ", x/y)
    print("The quotient is: ", x//y)
    print("The remainder is: ", x%y)
    break
  except ValueError as err:
    print("How can you perform arithmetic operations on strings?")
    print("So, please enter a number")
    print("--------------------------")
  except ZeroDivisionError as err:
    print("Division by 0 is undefined")
    print(err, 'How is it possible? Think youself once')
    print(err, 'Bozo, think about it') 
    print("--------------------------")
