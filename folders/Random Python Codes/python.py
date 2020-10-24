hrs = input("Enter Hours:")
rate = input("Rate per hour")
h = float(hrs)
r = float(rate)
if h < 40:
    pay = h*r
    print(pay)
else:
    pay = 40 * r
    r = 1.5*r
    pay = pay+(h-40)*r
print(pay)