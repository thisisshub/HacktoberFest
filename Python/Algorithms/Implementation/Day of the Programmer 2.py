def dayOfProgrammer(year):
    if year == 1918:
        print("26.09.1918")
    elif 1700 <= year <= 1917:
        if year % 4 == 0:
            print("12.09.", year, sep='')
        else:
            print("13.09.", year, sep='')
    else:
        if year % 4 == 0 and year % 100 != 0 or year % 400 == 0:
            print("12.09.", year, sep='')
        else:
            print("13.09.", year, sep='')


if __name__ == '__main__':
    year = int(input().strip())

    dayOfProgrammer(year)
