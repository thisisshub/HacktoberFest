alphabet = "abcdefghijklmnopqrstuvwxyz"

def encrypt(plaintext, key):
    encrypted = ""
    
    for letter in plaintext:
        alphabet_loc = (alphabet.find(letter) + int(key)) % 26 
        encrypted += alphabet[alphabet_loc]
    return encrypted


def decrypt(encrypted, key):
    decrypted = ""

    for letter in encrypted:
        alphabet_loc = (alphabet.find(letter) - int(key)) % 26 
        decrypted += alphabet[alphabet_loc]
    return decrypted


def main():
    print("Welcome to the Caesar Cypher.")
    key = input("Enter the rotation key you would like to use (0-25): ")
    func = input("Would you like to encrypt or decrypt (e/d)?: ")
    text = input("Enter the string: ")

    if func.lower() == "e":
        print("Your encrypted string is - " + encrypt(text, key))
    elif func.lower() == "d":
        print("Your decrypted string is - " + decrypt(text, key))
    else:
        print("Please try again. Your input function was invalid.")

if __name__=="__main__":
    main()
    