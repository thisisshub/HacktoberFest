# You are given n unit squares,
# and you are asked to make rectangles using these squares.
# You have to count the number of rotationally unique rectangles that you can make.
# Two rectangles are rotationally unique if one can’t be rotated to become equivalent to the other one.


def count_unique_rectangle(n):
    count=0
    for i in range(1, int(n**0.5) +1):
        height = i
        while (height*i) <=n:
            count +=1
            height+=1
    return count

print(count_unique_rectangle(int(input())))
