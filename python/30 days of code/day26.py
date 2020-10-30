x,y,z = map(int,input().split(' '))
a,b,c = map(int,input().split(' '))
if (x, y, z) == (a, b, c):
    print("0")
elif (y, z) == (b, c):
    print(15 * (x - a))
elif z==c:
    if y<=b and x<=a:
        print("0")
    else:
        print(500 * (y - b))
elif z>c:
    print("10000")
else:
    print("0")
