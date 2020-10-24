def repeatedString(s, n):
    print(s.count("a")*(n//len(s))+s[:n % len(s)].count("a"))


if __name__ == '__main__':
    s = input()

    n = int(input())
    repeatedString(s, n)
