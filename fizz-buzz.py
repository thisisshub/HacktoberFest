# fizzbuzz time!
# kwame taylor

def run_fizzbuzz(i):
    '''
    This function runs Kwame's fizzbuzz, which prints out numbers from 1 to i,
    except for each third number it fizz,
    every fifth number it prints buzz,
    every fifteenth number it prints fizzbuzz,
    and every other number prints as itself.
    '''
    fizzbuzz = 'fizzbuzz'
    fizz = 'fizz'
    buzz = 'buzz'

    for i in range(1, i+1):
        if i % 3 == 0 and i % 5 == 0:
            print(fizzbuzz)
        elif i % 3 == 0:
            print(fizz)
        elif i % 5 == 0:
            print(buzz)
        else:

            print(i)

i = 100
run_fizzbuzz(i)