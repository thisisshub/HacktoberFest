```python

class Stack():
    
    def __init__(self,list = None):
        if list == None:
            self.items = []
        else:
            self.items = list
    
    def push(self, item):
        self.items.append(item)
        # NO RETURN

    def pop(self):
        if not self.isEmpty():
            return self.items.pop()
        else:
            return 'Cannot pop, Stack is empty.'

    def peek(self):
        if not self.isEmpty():
            return self.items[-1]
        else:
            return 'Cannot peek, Stack is empty.'
    
    def isEmpty(self):
        return self.items == []

    def size(self):
        return len(self.items)

if __name__ == '__main__':
    s = Stack()
    name = input('Enter your name : ')
    for i in name:
        s.push(i)
    print(s.items)
    
    
        
```