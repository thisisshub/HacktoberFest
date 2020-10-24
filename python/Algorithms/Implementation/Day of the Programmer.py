def dayOfProgrammer(year):
    s=0
    if 1700 <= year <= 1917:
        if year % 4==0:
            for i in range(1, 9):
                if i % 2 == 0:
                    s += 30
                else:
                    s += 31
            print(256 - s, ".09", ".", year, sep='')
        else:
            for i in range(1, 9):
                if i % 2 == 0:
                    s += 30
                else:
                    s += 31
            s -= 1
            print(256 - s, ".09", ".", year, sep='')
    elif year == 1918:
        print('26.09.1918')
    else:
        if year % 4 == 0 and year % 100 != 0 or year % 400 ==0:
            for i in range(1,9):
                if i % 2==0:
                    s+=30
                else:
                    s+=31
            print(256-s,".09",".",year,sep='')
        else:
            for i in range(1, 9):
                if i % 2 == 0:
                    s += 30
                else:
                    s += 31
            s-=1
            print(256-s,".09",".",year,sep='')


if __name__ == '__main__':
    year = int(input().strip())

    dayOfProgrammer(year)