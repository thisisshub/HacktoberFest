n = int(input())
lis = []
for i in range(n):
    x = int(input())
    y = int(input())
    lis.append((x,y))
lines = []
horizontal_lines = []
for i in lis:
    for j in lis:
        if i!=j:
            if i[1] == j[1] and i[0]<j[0]:
                x = []
                x.append(i)
                x.append(j)
                lines.append(x)
                horizontal_lines.append(x)
            elif i[0] == j[0] and i[1]<j[1]:
                x = []
                x.append(i)
                x.append(j)
                lines.append(x)
steps = []
length = []
for i in horizontal_lines:
    x = [i]
    for j in lines:
        if i!=j:
            if x[-1][1] == j[0]:
                x.append(j)
    if len(x) != 1:
        steps.append(x)
        length.append(len(x))
big = 0
for i in length:
    if i>big:
        big = i
for i in steps:
    if len(i) == big:
        print(i);
