'''We sort a large sublist of a given list and go on reducing the size of the list until all elements are sorted.'''

def shellSort(input_list):
    mid = len(input_list) // 2
    while mid > 0:
        for i in range(mid, len(input_list)):
            temp = input_list[i]
            j = i
            # Sort the sub list for this gap
            while j >= mid and input_list[j - mid] > temp:
                input_list[j] = input_list[j - mid]
                j = j - mid
            input_list[j] = temp
        # Reduce the gap for the next element
        mid = mid // 2

list = [25, 2, 30, 1, 45, 39, 11, 110, 29]
shellSort(list)
print(list)