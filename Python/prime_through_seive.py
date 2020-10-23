from itertools import count


def prime_through_seive(natural_nums):
	num = next(natural_nums)
	yield (num)
	yield from prime_through_seive(n for n in natural_nums if n%num)


if __name__ == '__main__':

	natural = count(2)
	primes = prime_through_seive(natural)

	for i in range(100):
		print(next(primes))