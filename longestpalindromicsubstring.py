
# Expand in both directions of `low` and `high` to find maximum length palindrome
def expand(s, low, high):
    length = len(s)
 
    # expand in both directions
    while low >= 0 and high < length and s[low] == s[high]:
        low = low - 1
        high = high + 1
 
    # return palindromic substring
    return s[low + 1:high]
 
 
# Function to find the longest palindromic substring in `O(n²)` time and `O(1)` space
def findLongestPalindromicSubstring(s):
 
    # base case
    if not s or not len(s):
        return ''
 
    # `max_str` stores the maximum length palindromic substring found so far
    max_str = ''
 
    # `max_length` stores the maximum length of palindromic
    # substring found so far
    max_length = 0
 
    # consider every character of the given string as a midpoint and expand
    # in both directions to find maximum length palindrome
 
    for i in range(len(s)):
 
        # find the longest odd length palindrome with `s[i]` as a midpoint
        curr_str = expand(s, i, i)
        curr_length = len(curr_str)
 
        # update maximum length palindromic substring if the odd length
        # palindrome has a greater length
 
        if curr_length > max_length:
            max_length = curr_length
            max_str = curr_str
 
        # Find the longest even length palindrome with `s[i]` and `s[i+1]` as
        # midpoints. Note that an even length palindrome has two midpoints.
 
        curr_str = expand(s, i, i + 1)
        curr_length = len(curr_str)
 
        # update maximum length palindromic substring if even length
        # palindrome has a greater length
 
        if curr_length > max_length:
            max_length = curr_length
            max_str = curr_str
 
    return max_str
 
 
if __name__ == '__main__':
 
    s = 'ABDCBCDBDCBBC'
 
    print(f'The longest palindromic substring of {s} is',
            findLongestPalindromicSubstring(s))
