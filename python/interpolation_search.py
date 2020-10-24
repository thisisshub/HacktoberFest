"""
Implementation of Interpolation Search
"""


def interpolation_search(sample_input, lowest, highest, item):
    """
    function to search the item in a give list of item
    :param sample_input: list of number
    :param lowest: the lowest element on our list
    :param highest: the highest element on our list
    :param item: the item element to search in our list
    :return: true if found else fals
    """
    distance = item - sample_input[lowest]
    value_range = sample_input[highest] - sample_input[lowest]
    ratio = distance / value_range

    found = False
    estimation = int(lowest + ratio * (highest - lowest))

    if sample_input[estimation] == item:
        found = True
    elif item < sample_input[estimation]:
        highest = estimation
    else:
        lowest = estimation

    while lowest <= highest and not found:
        mid = (lowest + highest) // 2
        if sample_input[mid] == item:
            found = True
        elif sample_input[mid] < item:
            lowest = mid + 1
        else:
            highest = mid - 1
    return found


if __name__ == "__main__":
    sample_input = [0, 4, 7, 9, 12, 14, 18, 25, 27, 36, 46, 50, 64, 79, 88]
    item = int(input("Enter the item to search: "))
    result = interpolation_search(sample_input, min(sample_input), len(sample_input) - 1, item)
    if result:
        print("Successfully found")
    else:
        print("Not Found")
