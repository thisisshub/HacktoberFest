import time


def timeConversion(s):
    return time.strftime("%H:%M:%S",s)


if __name__ == '__main__':
    s = time.strptime(input(),"%I:%M:%S%p")

    result = timeConversion(s)

    print(result)