def hurdleRace(k, height):
    print(max(height)-k if max(height)-k>=0 else 0 )


if __name__ == '__main__':

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    height = list(map(int, input().rstrip().split()))

    hurdleRace(k, height)
