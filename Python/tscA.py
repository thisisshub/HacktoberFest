# Book Read/Write Cycle based problem

fbnp = int(input())
fbnl = int(input())
sbnp = int(input())
sbnl = int(input())
readspeed = int(input())
writespeed = int(input())
tsec = int(input())
out = ""

#Read Cycle
totallines1 = fbnp * fbnl
timetoread = totallines1 / readspeed
#print(timetoread)

#Write Cycle
totallines2 = sbnp * sbnl
timetowrite = totallines2 / writespeed
#print(timetowrite)

#speed = distance / time
if tsec <= timetoread:
    out = "READ"
    page = int((tsec * readspeed) // fbnl)
    line = int(fbnl % (tsec * readspeed))
    print(out,page,line)
else:
    out = "WRITE"
    page = int(((tsec - timetoread) * writespeed) // sbnl)
    line = int(((tsec - timetoread) * writespeed) % sbnl)
    print(out,page,line)
