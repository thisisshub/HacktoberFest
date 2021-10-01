#Bubble Sort
def bubble_sort(a):
    for x in range(0,len(a)-1):
        for y in range(0,len(a)-1-x):
            if a[y]>a[y+1]:
                a[y],a[y+1]=a[y+1],a[y]
    return a
def insertion_sort(a):
    for x in range(1,len(a)):
        tmp=a[x]
        for y in range(x-1,-2,-1):
            if tmp<a[y]:
                a[y+1]=a[y]
            else:
                break
        a[y+1]=tmp
    return a
def printlist(a,tmp,val="General"):
    print("resultant list by {} sort is".format(val))
    print(*a)
    print("time taken is {}".format(tmp))
def main():
    from time import time 
    inp=[int(x) for x in input().strip().split()]
    x=inp[:]
    start=time()
    bubble_sort(x)
    end=time()
    printlist(x,end-start,"Bubble")
    y=inp[:]
    start=time()
    insertion_sort(y)
    end=time()
    printlist(y,end-start,"Insertion")
#driver code
#test
if __name__=='__main__':
    main()