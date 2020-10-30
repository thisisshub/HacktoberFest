from collections import deque

r = deque()
for _ in range(int(input())):
    
    # * expands the list or tuple to positional arguments
    # [''] ensures that the list always has 2 elements at least
    # As pop doesn't need any argument, it is taken as empty ['pop', '']
    # But append and appendleft take an argument, it looks like ['append', '3', '']
    # Here, the extra element doesn't matter as we only take 0 and 1 elements
    eval("r.{0}({1})".format(*input().split()+['']))
print(*r)
