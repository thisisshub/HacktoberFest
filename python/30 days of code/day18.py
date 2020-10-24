from queue import LifoQueue

class Solution:
    stack = []
    queue = []

    def pushCharacter(self,n):
        self.stack.append(n)
        return self.stack

    def enqueueCharacter(self,n):
        self.queue.append(n)
        return self.queue

    def popCharacter(self):
        return self.stack.pop(-1)

    def dequeueCharacter(self):
        return self.queue.pop(0)

# read the string s
s = input()
# Create the Solution class object
obj = Solution()

l = len(s)
# push/enqueue all the characters of string s to stack
for i in range(l):
    obj.pushCharacter(s[i])
    obj.enqueueCharacter(s[i])
print(obj.stack)
print(obj.queue)
isPalindrome = True
'''
pop the top character from stack
dequeue the first character from queue
compare both the characters
'''
for i in range(l // 2):
    if obj.popCharacter() != obj.dequeueCharacter():
        isPalindrome = False
        break
# finally print whether string s is palindrome or not.
if isPalindrome:
    print("The word, " + s + ", is a palindrome.")
else:
    print("The word, " + s + ", is not a palindrome.")