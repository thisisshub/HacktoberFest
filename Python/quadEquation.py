#Solving a quadratic equation

# enter co-efficients
a = int(input("Enter A: "))
b = int(input("Enter B: "))
c = int(input("Enter C: "))

if(a == 0):
    print("This is not a quadratic equation.")
    

elif(b != 0 and c != 0):
    xi = ((-1*b)+(((b*b)-(4*a*c))**(1/2)))/(2*a)
    xii = ((-1*b)-(((b*b)-(4*a*c))**(1/2)))/(2*a)

    print("x1",xi,"\nx2",xii)

elif(b == 0 and c == 0):
    xi = 0
    xii = 0

    print("x1",xi,"\nx2",xii)

elif(b == 0):

    xi = ((-1*c)/a)**(1/2)
    xii = -1*((-1*c)/a)**(1/2)

    print("x1",xi,"\nx2",xii)

elif(c == 0):
    xi = 0
    xii = (-1*b)/a

    print("x1",xi,"\nx2",xii)
