  
from collections import deque

t = int(input())

for i in range(t):
    _ = int(input())
    
    # storing all the lengths into a deque
    # a deque can be accessed from both the ends
    lengths = deque(map(int, input().split()))
    for j in range(len(lengths)-1):
        
        # checking if first element is greater than second
        #if yes, then popping the leftmost element
        if lengths[0] >= lengths[1]:
            lengths.popleft()
        
        # checking if last element is greater than second last
        #if yes, then popping the last element
        elif lengths[-1] >= lengths[-2]:
            lengths.pop()
        else:
            break
        
    # finally we will be left with one element if all the cubes are piled up
    # so we check if length of deque is 1. if yes, we print yes. else, no
    if len(lengths) == 1:
        print("Yes")
    else:
        print("No")
