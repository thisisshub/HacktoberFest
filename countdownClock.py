from time import sleep

def countdown(n):
    for i in range(n, 0, -1):
        print(i)
        sleep(1)
    print("Ring!!!!!!!!!!!!!!!!!!!!!!!!!!")


if __name__ == "__main__":
    while True:
        try:
            second = int(input("Please input the number of seconds to countdown: "))
        except ValueError:
            print("Please enter an integer")
            continue

        if second < 1:
            print("Please enter a value more than 1")
        else:
            break

    countdown(second)
        