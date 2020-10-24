"""Simple, given a string of words, return the length of the shortest word(s).

String will never be empty and you do not need to account for different data types."""

def find_short(s):
    s = s.split()
    shortestLength = len(s[0])
    for item in s:
        if len(item) < shortestLength:
            shortestLength = len(item)
    return shortestLength
    
