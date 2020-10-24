z = input()
x = open(z)
lst = list()
count = dict()
for lines in x:
    if lines.startswith('From:'):
        z= lines.split()
        y= z[1]
        lst.append(y)
# dict are made only by going through lists, so it is necessary to look through lists using for loop.
for words in lst:
    count[words]= count.get(words, 0) +1

print(count)
