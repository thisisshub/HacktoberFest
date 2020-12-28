def magic_square(n):
    magic_sqr=[]
    for i in range(0,n):
        l=[]
        for j in range(0,n):
            l.append(0)

        magic_sqr.append(l)

    
    i=n//2
    j=n-1
    k=0

    while(k<n*n):
        if(i==-1 and j==n):
            j=n-2
            i=0
        else:
            if(j==n):
                j=0
            if(i<0):
                i=n-1
        if(magic_sqr[i][j]!=0):
            j=j-2
            i=i+1
            continue
        else:
            magic_sqr[i][j]=k
            k=k+1
        
        i=i-1
        j=j+1
    print("\n")
    for i in range(0,n):
        for j in range(0,n):
            print(magic_sqr[i][j],end=" ")
        print()
    
n=int(input("Enter the size of the magic square you want to know: "))
if (n%2==0):
    print("Can not made any magic square ")
else:
    magic_square(n)
