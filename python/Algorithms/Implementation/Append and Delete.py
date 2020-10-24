def appendAndDelete(s, t, k):
    c=0
    if s==t:
        print("Yes")
    else:
        if t.find(s):
            c=t.find(s)
    print()


if __name__ == '__main__':
    s = input()

    t = input()

    k = int(input())

    appendAndDelete(s, t, k)
