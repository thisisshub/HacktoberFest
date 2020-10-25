class Stack:
    def __init__(self,list_=None):
        if list_ == None:
            self.items = []
        else:
            self.items = list_[:]
    def size(self):
        return len(self.items)
    def push(self,x):
        self.items.append(x)
    def pop(self):
        if self.size()>0:
            return self.items.pop()
    def isEmpty(self):
        return self.size()==0

class Queue:
    def __init__(self,list_=None):
        if list_ == None:
            self.items = []
        else:
            self.items = list_
    def size(self):
        return len(self.items)
    def enQ(self,x):
        self.items.append(x)
    def deQ(self):
        if self.size()>0:
            return self.items.pop(0)
    def isEmpty(self):
        return self.size()==0

def ispalin(l):
    s=Stack(l)
    q=Queue(l)
    palin =True
    t = s.size()//2
    count = 0
    pa = s.size()
    while(s.size()>0):
    #     if(s.pop() == q.deQ()):
    #         t-=1
    #     else:
    #         palin = False
    #         break
    # return palin
        print(s.items," ",q.items)
        if(s.pop()==q.deQ()):
            count+=1    
        if(count == pa):
            return True
    return False

l = [c for c in input("input: ").split()]
print(ispalin(l))