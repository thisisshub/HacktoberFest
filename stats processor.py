def get_data():
    userin = input("Please enter 1 for a list, 2 for a frequency table or 3 for a stem and leaf. >>> ")
    if userin == "1":
        return [float(x) for x in input("Enter simple list separated by spaces >>> ").split(" ") if x]
    elif userin == "2":
        print("You should enter each row of the frequency table on each new line. The first space separated value should be the value, and the last the frequency")
        print("Just press enter twice to finish.")
        out = []
        get = input(">>> ")
        while get:
            get = get.split(" ")
            get[1] = int(get[1])
            get[0] = float(get[0])
            out += [get[0]]*get[1]
            get = input(">>> ")
        return out
    else:
        print("Enter each row of the stem and leaf on a new line, double press enter to stop inputting.")
        print("The first value should be the stem and all that follow the leaves.")
        out = []
        get = input(">>> ")
        while get:
            leaves = get.split(" ")
            stem = leaves.pop(0)
            for leaf in leaves:
                out.append(float(stem + leaf))
            get = input(">>> ")
        return out

def get_median(work):
    total = work[len(work)//2]
    if len(work) % 2 == 0: # even, need to add the next item
        total += work[len(work)//2 + 1]
        total /= 2
    return total

master = get_data()
master.sort()
print(master)
print("\n\n")
print("Mean:", sum(master) / len(master))


print("Median:", get_median(master))
print("Mode:", max(set(master), key=master.count))
print("Range:", max(master) - min(master))

B = master[:len(master)//2]
C = master[len(master)//2:]
if len(C) > len(B):
    C.pop(0)

print("IQR:", get_median(C) - get_median(B))