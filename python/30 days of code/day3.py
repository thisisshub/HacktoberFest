def solve(n):
    if n % 2==0:
        if 2 <= n <= 5:
            return print("Not Weird")
        if 6 <= n <= 20:
            return print("Weird")
        if n > 20:
            return print("Not Weird")
    else:
        return print("Weird")


if __name__ == '__main__':
    n=int(input())
    solve(n)