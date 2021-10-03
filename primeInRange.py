lr=int(input("Enter lower range: "))
ur=int(input("Enter upper range: "))
for i in range(lr,ur+1):
    count=0
    for j in range(1,i+1):
        if i%j==0:
            count+=1
    if count==2:
        print(str(i)+" is a prime number")
    if(i==1):
        print(str(i)+" Neither a prime nor composite")
        

