# Add all the natural numbers below 1000 that are multiples of 3 or 5.


def multiples_of_3_or_5():
    for number in range(1000):
        if not number % 3 or not number % 5:
            yield number


print sum(multiples_of_3_or_5())
