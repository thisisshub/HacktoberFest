def kangaroo(x1, v1, x2, v2):
    if (abs(v1-v2))==0 or(x2>x1 and v2>v1):
        print("NO")
    elif abs(x1 - x2)% abs(v1 - v2) == 0:
        print("YES")
    else:
        print("NO")


if __name__ == '__main__':
    x1V1X2V2 = input().split()

    x1 = int(x1V1X2V2[0])

    v1 = int(x1V1X2V2[1])

    x2 = int(x1V1X2V2[2])

    v2 = int(x1V1X2V2[3])

    kangaroo(x1, v1, x2, v2)