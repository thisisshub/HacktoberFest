t = int(input())
d= {}
c = 0
while c < t:
    n = input()
    l = n.split(' ')
    d[l[0]] = l[1]
    c +=1
c=0
while True:
    try:
        n = input()
        if n in d:
            print(n + '=' + d[n])
        else:
            print("Not found")
    except EOFError as error:
        break