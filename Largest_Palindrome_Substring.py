# PYTHON PROGRAM TO PRINT LARGEST PALINDROMIC SUBSTRING

def palinString(ex):
    string_size = len(ex)
    for str_length in range(string_size, 0, -1):
        i = 0
        for get_str_size in range(str_length, string_size + 1):
            made_str = ex[i:str_length + i:1]
            rev_str = made_str[::-1]
            if made_str == rev_str:
                return made_str
            i += 1


print(palinString(input("ENTER STRING...")))