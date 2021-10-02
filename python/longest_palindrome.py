class Solution:
    def longest_Palindrome(self, s):
      array = [[False for i in range(len(s))]for i in range(len(s))]
      for i in range(len(s)):
          array[i][i] = True
      max_length = 1
      start = 0
      for length in range(2,len(s)+1):
          for i in range(len(s)-length+1):
              end = i + length
              if length == 2:
                  array[i][end-1] = True
                  max_length = length
                  start = i
              else:
                  if s[i] == s[end-1] and array[i+1][end-2]:
                      array[i][end-1] = True
                      max_length = length
                      start = i
                  
      return s[start:start+max_length]

# Test program
s = "geeks"
print(str(Solution().longest_Palindrome(s)))
d = "racecar"
print(str(Solution().longest_Palindrome(d)))