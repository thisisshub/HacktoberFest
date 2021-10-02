# Function to implement the KMP algorithm
def KMP(X, Y):
 
    # base case 1: `Y` is None or empty
    if Y is None or not Y:
        print("The pattern occurs with shift 0")
        return
 
    # base case 2: `X` is None, or X's length is less than that of Y's
    if X is None or len(Y) > len(X):
        print("Pattern not found")
        return
 
    chars = list(Y)
 
    # `next[i]` stores the index of the next best partial match
    next = [0] * (len(Y) + 1)
 
    for i in range(1, len(Y)):
        j = next[i + 1]
 
        while j > 0 and chars[j] is not chars[i]:
            j = next[j]
 
        if j > 0 or chars[j] == chars[i]:
            next[i + 1] = j + 1
 
    j = 0
    for i in range(len(X)):
 
        if j < len(Y) and X[i] == Y[j]:
            j = j + 1
            if j == len(Y):
                print("Pattern occurs with shift", (i - j + 1))
        elif j > 0:
            j = next[j]
            i = i - 1        # since `i` will be incremented in the next iteration
 
 
# Program to implement the KMP algorithm in Python
if __name__ == '__main__':
 
    text = "ABCABAABCABAC"
    pattern = "CAB"
 
    KMP(text, pattern)
