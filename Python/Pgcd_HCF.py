def HCF(x,y): 
    if(y==0): 
        return x
    else: 
        return hcfnaive(y,x%y) 
  
x = 128
y= 46
  
# prints 12 
print ("The gcd of128 and 46 is : ",end="") 
print (HCF(120,46))
