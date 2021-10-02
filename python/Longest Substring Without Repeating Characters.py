class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        res = 0
        d = {}
        i = 0
        j = 0
        while j < len(s):
            if s[j] in d:
                i = max(i,d[s[j]])
            d[s[j]] = j+1
            j+=1
            res = max(res,j-i)
        return res
                
            



class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        str_list = []
        max_length = 0

        for x in s:
            if x in str_list:
                str_list = str_list[str_list.index(x)+1:]

            str_list.append(x)    
            max_length = max(max_length, len(str_list))

        return max_length


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_len = 0
        d = {}
        i = 0
        j = 0
        while j < len(s):
            if s[j] in d:
                i = max(d[s[j]],i)
            max_len = max(max_len,j-i+1)
            d[s[j]] = j+1
            j+=1
        return max_len
        


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        ans = 0
        d = {}
        i = 0
        for j in range(n):
            if s[j] in d:
                i = max(d[s[j]],i)
            
            ans = max(ans,j-i+1)
            d[s[j]] = j+1
        return ans
