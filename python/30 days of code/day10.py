if __name__ == '__main__':
    n = int(input())
    print(max(len(i) for i in bin(n)[2:].split('0')))