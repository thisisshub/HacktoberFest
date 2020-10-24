import random
import string

def passwords():
	length = random.randint(10,18)
	printable = string.ascii_letters + string.digits + string.punctuation
	return ''.join(random.choice(printable) for c in range(length))

print(passwords())