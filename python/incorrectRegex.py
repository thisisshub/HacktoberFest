import re

for _ in range(int(input())):
    try:
        
        # compile()
        # Regex are compiled into pattern objects using compile(), which have methods for various operations
        # such as searching for pattern matches or performing string substitutions.
        r = re.compile(input())
        print("True")
    except re.error:
        print("False")
