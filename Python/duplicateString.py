# removing repeated characters from a string

def removeDuplicateChar(str, n): 
      
    # Used as index in altered string 
    index = 0
      
    # Traverse through all characters 
    for i in range(0, n): 
        # Check if str[i] is present before it  
        for j in range(0, i + 1): 
            if (str[i] == str[j]): 
                break          
        # If not present, then add it to result
        if (j == i): 
            str[index] = str[i] 
            index += 1
              
    return "".join(str[:index]) 
  
# main code
t = input("Enter string: ")
n = len(t)
print("Altered string: ", end='')
print(removeDuplicateChar(list(t), n)) 