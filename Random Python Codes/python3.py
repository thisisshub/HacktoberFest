hrs = input("Enter Hours:")
rate = input("Rate per hour")
q = float(hrs)
w = float(rate)
def computepay(h,r):
    if h < 40:
        pay = h*r
        print(pay)
    else:
        pay = 40 * r
        r = 1.5*r
        pay = pay+(h-40)*r
        return pay
pay=computepay(q,w)
print("Pay",pay)