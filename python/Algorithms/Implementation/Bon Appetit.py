def bonAppetit(bill, k, b):
    s = 0
    s=s-bill[k]
    for i in range(0, len(bill)):
        s+=bill[i]
    s=int(s/2)
    if b-s==0:
        print("Bon Appetit")
    else:
        print(b-s)


if __name__ == '__main__':
    nk = input().rstrip().split()

    n = int(nk[0])

    k = int(nk[1])

    bill = list(map(int, input().rstrip().split()))

    b = int(input().strip())

    bonAppetit(bill, k, b)
