
def compress(st):
    result = ""
    i = 0
    length = len(st)
    while i < length:
        temp = st[i]
        count = 1
        i += 1
        while i < length and st[i] == st[i-1]:
            i += 1
            count += 1
        result += temp + str(count)

    return result

if __name__ == "__main__":
    print(compress("AAAABBBBCCCCDDD"))
    print(compress("aa    RRED"))
