
class meg:
    def __init__(self, arr):
        self.arr = arr

    def merge(self, left, right):
        i = left[1]
        # j = right[0]
        for i in range(right[0], right[1] + 1):
            while i > left[0]:
                if self.arr[i] > self.arr[i - 1]:
                    self.arr[i], self.arr[i - 1] = self.arr[i - 1], self.arr[i]
                i = i - 1
        return list([left[0], right[1]])

    def mergeSOrt(self, start, end):
        if end == start:
            return list([start, end])
        else:
            half = int((start + end) / 2)
            left = self.mergeSOrt(start, half)
            right = self.mergeSOrt(half + 1, end)
            return self.merge(left, right)
   
    def function(self):
        arr = self.mergeSOrt(0, len(self.arr) - 1)
        print(self.arr)
        

if __name__ == "__main__":
    print("enter the size of array")
    s = int(input())
    lArray = []
    print("enter the data to the array")
    for _ in range(s):
        val = int(input())
        lArray.append(val)
    print(lArray)
    a = meg(lArray)
    a.function()
