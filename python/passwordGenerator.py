from random import randint

def generatePass(n):
    password = ""
    for i in range(n):
        password += chr(randint(33, 126))
    return password


if __name__ == "__main__":
    print(generatePass(10))