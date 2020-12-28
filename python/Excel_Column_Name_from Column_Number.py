MAX = 50
 
# Function to print Excel column name 
# for a given column number

def printString(n):
 

    # To store result (Excel column name)

    string = ["\0"] * MAX
 

    # storing current index in str which is result

    i = 0
 

    while n > 0:

        # Find remainder

        rem = n % 26
 

        # if remainder is 0, then a 

        # 'Z' must be there in output

        if rem == 0:

            string[i] = 'Z'

            i += 1

            n = (n / 26) - 1

        else:

            string[i] = chr((rem - 1) + ord('A'))

            i += 1

            n = n / 26

    string[i] = '\0'
 

    # Reversing the string

    string = string[::-1]

    print "".join(string)
 
# Examples of the program 

printString(26)

printString(702)

printString(705)