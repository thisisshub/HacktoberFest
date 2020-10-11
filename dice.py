#!/usr/bin/env python

import sys
from random import randint


def roll(dices, sides, again):
	print("Roll the dices!")

	while True:
		for i in range(1, dices + 1):
			print("dice " + str(i) + " - " + str(randint(1, sides)))
		print("")
		if again:
			if (str(input("roll again? ")).upper()) == "N":
				break
		else:
			break


if __name__ == '__main__':
	dices = 1
	sides = 6
	again = False

	for i in range(len(sys.argv)):
		argument = sys.argv[i]
		if argument == "-h" or argument == "--help":
			print("usage: dice.py [--help] [--dices=int] [--sides=int] [--again]")
			print("")
			print("  --help\tshow this help message")
			print("  --dices\tset the number of dices (parameter as integer) standard: 1 dice")
			print("  --sides\tset the number of dice sides (parameter as integer) standard: 6 sides")
			print("  --again\tthe dice-script ask to dice again")
			print("")
			print("example:")
			print("python3 dice.py --dices=6")
			print("  rolles six 6-sides dices")
			print("python3 dice.py --dices=3 --sides=10 --again")
			print("  rolles three 10-sides dices an ask to roll again")
			exit()
		if "--dices" in argument:
			dices = int(argument.split("=")[1])
		if "--sides" in argument:
			sides = int(argument.split("=")[1])
		if "--again" in argument:
			again = True

	roll(dices, sides, again)

