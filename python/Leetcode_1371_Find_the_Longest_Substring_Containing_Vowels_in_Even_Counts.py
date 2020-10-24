'''
Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

Example 1:
Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.

Example2:

Input: s = "leetcodeisgreat"
Output: 5
Explanation: The longest substring is "leetc" which contains two e's.
'''

'''
This can be solved using concept of Bitmasking

1. To solve this question in O(n) time, realise that a  mask of vowels "00000" can be used. Since, we only need to 
check whether count of any vowel is odd or even, we canuse 1/0 to denote odd and even.

2. Now, if suppose we have  curr = "00010" i.e. till " j " i.e count of b is odd and other vowels is even. If we encounter this again at "i" index, then we can say that:
count of vowels from s[j+1:i] (i inclusive, j exclusive) is even.

3.therefore length becomes "i - j". This can be comparedwith max_len.

'''


class Solution:

    '''
    Time Complexity O(n)
    Space Complexity O(1) (there are only 5 vowels)
    '''

    @staticmethod
    def findTheLongestSubstring(s):
        hashmap = {"a":1,"e":2,"i":3,"o":4,"u":32}
        res = 0
        seen = {0:-1}
        cur = 0
        for i,c in enumerate(s):
            cur ^= 1 << (hashmap.get(c,0)) >> 1
            seen.setdefault(cur,i)
            res = max(res,i - seen[cur])
        return res

# Driver Code
if __name__ == "__main__":
    s = "leetcodeisgreat"
    result = Solution.findTheLongestSubstring(s)
    print("length of longest Substring = ", result)