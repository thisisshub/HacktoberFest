class Stack:
    def __init__(self,list = None):
        if list == None:
            self.items=[]
        else:
            self.items = list

    def push(self,i):
        self.items.append(i)

    def size(self):
        return len(self.items)

    def isEmpty(self):
        if len(self.items)==0:
            return True
        else :
            return False

    def pop(self):
        if len(self.items)>0:
            return self.items.pop()
        else:
            print("you can't pop anymore Stack is EMPTY")

    def peek(self):
        return self.items[len(self.items)-1]


pa = Stack()
s= input()

print(s)
for i in s:
    if i in ['(','{','[']:
        pa.push(i)

    if i ==')' and pa.peek()=='(' \
            or i == '}' and pa.peek() == '{'\
            or i == ']' and pa.peek() == '[':
        pa.pop()

print(pa.items)
if pa.isEmpty():
    print("match")
else :
    print("Not match")


