def swastika(row,col): 
      
    for i in range(row): 
        for j in range(col):  
            if(i < row // 2):  
                if (j < col // 2):  
                    if (j == 0): 
                        print("*", end = "") 
                    else: 
                        print(" ", end = " ") 
                elif (j == col // 2): 
                    print(" *", end = "") 
                else: 
                    if (i == 0): 
                        print(" *", end = "") 
                          
            elif (i == row // 2): 
                print("* ", end = "") 
            else:  
                if (j == col // 2 or j == col - 1): 
                    print("* ", end = "") 
                elif (i == row - 1):  
                    if (j <= col // 2 or j == col - 1): 
                        print("* ", end = "") 
                    else: 
                        print(" ", end = " ") 
                else: 
                    print(" ", end = " ") 
        print() 
row = 7; col = 7
swastika(row, col)
