
def merge_lists(left_sublist, right_sublist):
    i, j = 0, 0
    result = []
    while i < len(left_sublist) and j < len(right_sublist):
        if left_sublist[i] <= right_sublist[j]:
            result.append(left_sublist[i])
            i += 1
        else:
            result.append(right_sublist[j])
            j += 1
    result += left_sublist[i:]
    result += right_sublist[j:]
    return result


def merge_sort(input_list):
    if len(input_list) <= 1:
        return input_list
    else:
        midpoint = int(len(input_list)/2)
        left_sublist = merge_sort(input_list[:midpoint])
        right_sublist = merge_sort(input_list[midpoint:])
        return merge_lists(left_sublist, right_sublist)


number_list = [4, 7, 54, 91, 34, 1, 4, 2, 6, 23, 12]
print(merge_sort(number_list))
