
def move(n,A,B,C):
    if n > 0:
        move(n-1,A,C,B)
        lst[C-1].append(lst[A-1].pop())
        print("move",n,"from ", chr(ord('A')+A-1), "to", chr(ord('A')+C-1))
        print("|  |  |")
        print_lst(lst[0], lst[1], lst[2], size)
        move(n-1,B,A,C)

def print_lst(a,b,c,x):
    #print(a,b,c,x)
    if x == 0:
        #print(a,b,c,x)
        return
    else:
        if len(a)>=x:
            print(a[x-1], end='  ')
        else:
            print("| ", end=' ')
        if len(b)>=x:
            print(b[x-1], end='  ')
        else:
            print("| ", end=' ')
        if len(c)>=x:
            print(c[x-1], end='  ')
        else:
            print("| ", end=' ')
        print()
        print_lst(a,b,c,x-1)

def init(n):
    if n == 0:
        return []
    return [n] + init(n-1)

size = int(input("Enter Input : "))
#size = 4
lst = [[]]*3
lst[0] = init(size)
lst[1] = list()
lst[2] = list()
#print(id(lst[0]), id(lst[1]), id(lst[2]))
print("|  |  |")
print_lst(lst[0],lst[1],lst[2],size)
move(size,1,2,3)