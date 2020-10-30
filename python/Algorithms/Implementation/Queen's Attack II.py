def queensAttack(n, k, r_q, c_q, obstacles):
    for i in range(n):
        for j in range(i,n):
            print(i)


if __name__ == '__main__':

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    r_qC_q = input().split()

    r_q = int(r_qC_q[0])

    c_q = int(r_qC_q[1])

    obstacles = []

    for _ in range(k):
        obstacles.append(list(map(int, input().rstrip().split())))

    queensAttack(n, k, r_q, c_q, obstacles)
