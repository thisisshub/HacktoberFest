from collections import Counter

company_name = input()

a = list(sorted(company_name))

# stores the keys and values of all the alphabets
b = Counter(a)

# taking all the keys and values after into a list 
r = list(b.keys())
p = list(b.values())

for i in range(3):
    
    # index is used to get the index number of the element in a list
    # getting the index of max repeated element
    temp = p.index(max(p))
    print(r[temp], p[temp])
    r.remove(r[temp])
    p.remove(p[temp])
