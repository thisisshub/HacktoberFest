def multiplication_table():
  user_input = int(input('Insert any number of multiplication: '))

  row = [] #  giving a row

  #  Make a columns and result the multiplication
  for i in range(1, user_input+1):
      row.append([])
      for j in range(1, user_input+1):
          row[i-1].append(i*j)
        
  #  return columns fit to the index
  print(' *{:>3}|'.format(' '), end='')
  for column in range(1, user_input+1):
      print('{:^6}'.format(column), end='')
  else:
      print()
      print('-' * (6 * (user_input+1)))
    
  #  print the result of the multiplication
  for index, value, in enumerate(row):
      print('{:^2}{:^3}|'.format(' ', index+1),end='')
      for answer in value:
        print(' {:^4} '.format(answer), end='')
      else:
          print('\n', end='')

  print('-' * (6 * (user_input+1)))

multiplication_table()
