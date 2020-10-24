# Program to play Stone, Paper, Scissor
import random

print('~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Stone-Paper-Scissor~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~')
name=input('Enter your name: ').capitalize()
while True:
	# sps=[' '*39+'Computer'+(' '*47).replace(' '*(int(len(name)/2)),name),[
	sps=[' '*39+'Computer'+' '*10+' '*(37-int(len(name)/2))+name,[
	'                                                   ',
	'                                    ______________ ',
	'                                   |//////////////|',
	'                                   |//////////////|',
	'                                   |/////Stone////|',
	'                                   |//////////////|',
	'                                   |______________|',
	'                                                   ',
	'                                                   '
	],[
	'                                                   ',
	'                                    ______________ ',
	'                                   |              |',
	'                                   |              |',
	'                                   |     Paper    |',
	'                                   |              |',
	'                                   |______________|',
	'                                                   ',
	'                                                   '
	],[
	'                                     __            ',
	'                                    |__|      __   ',
	'                                        \\    /     ',
	'                                         \\  /      ',
	'                                   Scissor\\/       ',
	'                                          /\\       ',
	'                                         /  \\      ',
	'                                     __ /    \\__   ',
	'                                    |__|           '
	]]

	print('1) Stone\n2) Paper\n3) Scissor')
	ran=random.choice([1,2,3])
	inp=int(input('Enter the Option number: '))
	if ran==inp:
		result='Match Draw'
	elif (ran,inp)==(1,2) or (ran,inp)==(2,3) or (ran,inp)==(3,1):
		result=' You Won  '
	elif (ran,inp)==(3,2) or (ran,inp)==(2,1) or (ran,inp)==(1,3):
		result=' You Lose '

	print(sps[0])
	for i in range(9):
		print(f'{sps[ran][i]}',end='')
		(print(' '*13+result+' '*12,end=''),print(f'{sps[inp][i].lstrip()}')) if i==4 else print(f'{sps[inp][i]}')

	try:
		if int(input('\nTo play the Game Again Press "1" & "0" to Quit: '))!=1:
			exit('\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Thank You~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~')
	except:
		exit('\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Thank You~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~')
