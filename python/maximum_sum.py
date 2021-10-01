# Function to find contiguous sublist with the largest sum
# in a given set of integers
def kadane(A):
 
    # stores the sum of maximum sublist found so far
    max_so_far = 0
 
    # stores the maximum sum of sublist ending at the current position
    max_ending_here = 0
 
    # traverse the given list
    for i in range(len(A)):
 
        # update the maximum sum of sublist "ending" at index `i` (by adding the
        # current element to maximum sum ending at previous index `i-1`)
        max_ending_here = max_ending_here + A[i]
 
        # if the maximum sum is negative, set it to 0 (which represents
        # an empty sublist)
        max_ending_here = max(max_ending_here, 0)
 
        # update result if the current sublist sum is found to be greater
        max_so_far = max(max_so_far, max_ending_here)
 
    return max_so_far
 
 
# Function to find the maximum sum circular sublist in a given list
def runCircularKadane(A):
 
    # empty array has sum of 0
    if len(A) == 0:
        return 0
 
    # find the maximum element present in a given list
    maximum = max(A)
 
    # if the list contains all negative values, return the maximum element
    if maximum < 0:
        return maximum
 
    # negate all elements in the list
    for i in range(len(A)):
        A[i] = -A[i]
 
    # run Kadane’s algorithm on the modified list
    neg_max_sum = kadane(A)
 
    # restore the list
    for i in range(len(A)):
        A[i] = -A[i]
 
    ''' return the maximum of the following:
        1. Sum returned by Kadane’s algorithm on the original list.
        2. Sum returned by Kadane’s algorithm on modified list +
           the sum of all elements in the list.
    '''
 
    return max(kadane(A), sum(A) + neg_max_sum)
 
 
if __name__ == '__main__':
 
    A = [2, 1, -5, 4, -3, 1, -3, 4, -1]
 
    print("The sum of the sublist with the largest sum is", runCircularKadane(A))
