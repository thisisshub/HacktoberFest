def catAndMouse(x, y, z):
    if abs(z - x) > abs(z-y):
        print("Cat B")
    elif abs(z-y)>abs(z-x):
        print("Cat A")
    elif abs(z-y)==abs(z-x):
        print("Mouse C")


if __name__ == '__main__':
    q = int(input())

    for q_itr in range(q):
        xyz = input().split()

        x = int(xyz[0])

        y = int(xyz[1])

        z = int(xyz[2])

        catAndMouse(x, y, z)