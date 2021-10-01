# Find a sorted triplet in a given list
def findTriplet(A):
 
    # size of the input list
    n = len(A)
 
    # a sorted triplet is not possible on input having less than 3 elements
    if n < 3:
        return ()
 
    # `min[i] = j`, when `0 <= j < i` and `A[j] < A[i]`
    # `min[i] = -1` when `A[j] > A[i]` for every index `j < i`
    min = [-1] * n
 
    # keep an index to the minimum element found so far
    # while traversing the list from left to right
    min_index_so_far = 0
 
    # start from the 1st index as `min[0]` would be -1
    for i in range(1, n):
        # update `min_index_so_far` if the current index has less value;
        # otherwise, update `min[i]` with the smallest index to its left
        if A[i] < A[min_index_so_far]:
            min_index_so_far = i
        elif A[i] > A[min_index_so_far]:
            min[i] = min_index_so_far
 
    # `max[i] = j`, when `i < j < n` and `A[i] < A[j]`
    # `max[i] = -1` when `A[j] < A[i]` for every index `j > i`
    max = [-1] * n
 
    # keep an index to the maximum element found so far
    # while traversing the list from right to left
    max_index_so_far = n - 1
 
    # start from the second last index as `max[n-1]` would be `-1`
    for i in reversed(range(n - 1)):
 
        # update `max_index_so_far` if the current index has more value;
        # otherwise, update `max[i]` with the greatest index to its right
        if A[i] > A[max_index_so_far]:
            max_index_so_far = i
        elif A[i] < A[max_index_so_far]:
            max[i] = max_index_so_far
 
    # traverse the list again and find an index with both a min
    # element on its left and a max element on its right
    for i in range(n):
        if min[i] != -1 and max[i] != -1:
            # create a tuple of the found triplet and returns true
            return min[i], i, max[i]
 
    # no triplet found
    return ()
 
 
if __name__ == '__main__':
 
    # input list
    input = [5, 4, 3, 7, 6, 1, 9]
 
    # create a tuple to store the triplet
    first, second, third = findTriplet(input)
 
    # find triplet
    if first:
        print("Triplet found:", (input[first], input[second], input[third]))
    else:
        print("Triplet not found")
