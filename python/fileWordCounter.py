### .txt File Word Counter ###

# ask user for file name
print("Welcome to this word counter program!")
print("I can count the words of any .txt file.")
fileNotCounted = True

while fileNotCounted:
    print("Which file do you want me to count?")
    fileName = input()
    
    # check file ends in .txt
    while fileName[-4:] != '.txt':
        print("I'm afraid I can't count that file.")
        print("I can count the words of any .txt file.")
        print("Which file do you want me to count?")
        fileName = input()

    # check file exists
    try:
        file = open(fileName, "rt")
        # read file
        data = file.read()
        words = data.split()

        print("Word Count for "+fileName+" is: ",len(words))
        fileNotCounted = False
    except FileNotFoundError:
        print("That file doesn't seem to exist.")
        print("Make sure it is placed in the same folder as this program.")

