while True:
	def plot():
		print(f'''
                             |         |                                                   |         |
                    {indx[1]}|{indx[2]}|{indx[3]}                   ___               1    |    2    |    3    
                    _________|_________|_________                      \\          _________|_________|_________
                             |         |                   Positions    \\                  |         |
                    {indx[4]}|{indx[5]}|{indx[6]}       =================>            4    |    5    |    6    
                    _________|_________|_________                       /         _________|_________|_________
                             |         |                            ___/                   |         |
                    {indx[7]}|{indx[8]}|{indx[9]}                                     7    |    8    |    9    
                             |         |                                                   |         |

		''')
	
	indx=[False,' '*9,' '*9,' '*9,' '*9,' '*9,' '*9,' '*9,' '*9,' '*9]
	print('~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~TIC-TAC-TOE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~')
	# n=input('Choose the MOD of your Game:\n1) Press "1" for PC v/s Human\n2) Press "2" for Human v/s Human\nChoice:')
	print('Enter Your Names:')
	player=[input('\nPlayer 1: ').capitalize(),input('\nPlayer 2: ').capitalize()]
	used=[]
	choice=[]

	while choice==[]:
		choice.append(input(f'\n{player[0]} enter your Choice (X/O): ').upper())
		choice.append('O') if choice[0]=='X' else (choice.append('X') if choice[0]=='O' else (choice.pop(),print('\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Enter the Valid Choice ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\a\n')))
	print(f'~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ {player[0]}({choice[0]})  v/s  {player[1]}({choice[1]}) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~')

	while len(used)!=9:
		plot()
		try:
			temp=int(input(f'{player[len(used)%2]} enter the Place no. for ({choice[len(used)%2]}):'))
			if 0<temp<10:
				pass
			else:
				temp=int('traceback')
		except:
			print('\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Enter the Valid Place no. (1-9) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\a')
			continue

		if temp not in used: 
			indx[temp]=' '*4+choice[len(used)%2]+' '*4
			used.append(temp)
		else:
			print(f'\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Place {temp} is already Occupied by "{indx[temp].strip()}" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\a')
			continue
		
		for i in range(0,7,3):
			if indx[i+1]==indx[i+2]==indx[i+3] and indx[i+1]!=' '*9:
				won=player[choice.index(indx[i+1].strip())]
				indx[0]=True

		
		for i in range(0,3):
			if indx[i+1]==indx[i+4]==indx[i+7] and indx[i+1]!=' '*9:
				won=player[choice.index(indx[i+1].strip())]
				indx[0]=True

		if indx[1]==indx[5]==indx[9] and indx[1]!=' '*9:
			won=player[choice.index(indx[i+1].strip())]
			indx[0]=True
			
		if indx[3]==indx[5]==indx[7] and indx[3]!=' '*9:
			won=player[choice.index(indx[i+1].strip())]
			indx[0]=True
		
		if indx[0]==True:
			plot()
			print(f'~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ {won} won the Match ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\a\n')
			break
	else:
		plot()
		print(f'\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ The Match is Draw between {player[0]} & {player[1]} ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\a\n')
	
	try:
		if int(input('To play the Game Again Press "1" & "0" to Quit: '))!=1:
			exit('\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Thank You~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~')
	except:
		exit('\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Thank You~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~')
