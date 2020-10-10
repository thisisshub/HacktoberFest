# Program make a simple calculator

# This function adds two numbers
def add(x, y):
    return x + y

# This function subtracts two numbers
def subtract(x, y):
    return x - y

# This function multiplies two numbers
def multiply(x, y):
    return x * y

# This function divides two numbers
def divide(x, y):
    return x / y


print("Select operation.")
print("1.Add")
print("2.Subtract")
print("3.Multiply")
print("4.Divide")
print("5.Exit")
# Take input from the user
choice = input("Enter choice(1/2/3/4/5): ")

while True:
	if choice == '5':
		print ("Thank you for using me")
		break
	print ("Enter Two Numbers separated by space")
	numbers = input().split()
	num1 = int(numbers[0])
	num2 = int(numbers[1])
	if choice == '1':
		ans = add(num1, num2)
	elif choice == '2':
		ans = subtract(num1, num2)
	elif choice == '3':
		ans = multiply(num1, num2)
	elif choice == '4':
		ans = divide(num1, num2)
	else:
		print("Invalid Choice, please choose again")

	print ("The required answer is:",ans)
