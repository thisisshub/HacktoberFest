from collections import deque
 
 
# A class to represent an interval
class Interval:
    def __init__(self, begin, end):
        self.begin = begin
        self.end = end
 
    def __repr__(self):
        return str((self.begin, self.end))
 
 
# Function to merge overlapping intervals
def mergeIntervals(intervals):
 
    # sort the intervals in increasing order of their starting time
    intervals.sort(key=lambda x: x.begin)
 
    # create an empty stack
    stack = deque()
 
    # do for each interval
    for curr in intervals:
 
        # if the stack is empty or the top interval in the stack does not overlap
        # with the current interval, push it into the stack
        if not stack or curr.begin > stack[-1].end:
            stack.append(curr)
 
        # if the top interval of the stack overlaps with the current interval,
        # merge two intervals by updating the end of the top interval
        # to the current interval
        if stack[-1].end < curr.end:
            stack[-1].end = curr.end
 
    # print all non-overlapping intervals
    while stack:
        print(stack.pop())
 
 
if __name__ == '__main__':
 
    intervals = [Interval(1, 5), Interval(2, 3), Interval(4, 6),
                Interval(7, 8), Interval(8, 10), Interval(12, 15)]
 
    mergeIntervals(intervals)
