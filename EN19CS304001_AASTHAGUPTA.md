## Hi Aastha Gupta here CS-AI student
## ENROLLMENT NO. EN19CS304001
## Angle finder code in python
import math

a=float(input('Enter the perpendicular '))
b=float(input('Enter the base '))
x=a/b
d=math.atan(x)
degree=round(math.degrees(d))
print(str(degree)+'\xb0')
