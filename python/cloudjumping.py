# import math
# import os
# import random
# import re
# import sys

# Complete the jumpingOnClouds function below.
def jumpingOnClouds(c):
    i,jump = 0,0
    n = len(c)
    print(c)
    #f = lambda x,y: x+y
    while(i <= n-2):
        try:
            if c[i+2] == 0:
                i = i+2
        except:
            if c[i+1] == 0:
                i = i+1
        finally:
                jump = jump +1
    return jump

if __name__ == '__main__':
    # fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    c = list(map(int, input().rstrip().split()))

    result = jumpingOnClouds(c)

    print(str(result)+'\n')

    # fptr.write(str(result) + '\n')

    # fptr.close()
