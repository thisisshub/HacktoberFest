#  Shorten a name
#  For example Michael Henderson --> Henderson, M.
#  Hope you enjoy

def name_shorten(user_name):
	name_lst = user_name.split()

	print(name_lst[-1].capitalize(), end = '')

	# Case if name have only 1 word
	if (len(name_lst) > 1):
		print(",", end = '')

	for i in range(len(name_lst)-1):
		# print first word with capital ' <huruf awal nama 1 kata dengan kapital>.'
		print(' ' + name_lst[i][0].capitalize(), end = '.') 

name_shorten('Michael Henderson')
