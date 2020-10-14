import array


class Node:
    def __init__(self, head):
        self.head = head
        self.next = None


class LinkedList:

    def __init__(self):
        self.start = None

    def view_list(self):
        if self.start is None:
            print("List is empty")

        else:
            temp = self.start
            while temp is not None:
                print(temp.head)
                temp = temp.next

    def length(self):
        len = 0
        temp = self.start
        while temp.next is not None:
            temp = temp.next
            len += 1
        return len + 1

    def insert_last(self, data):
        new_node = Node(data)
        if self.start is None:
            self.start = new_node
        else:
            temp = self.start
            while temp.next is not None:
                temp = temp.next

            temp.next = new_node

    def insert_start(self, data):
        temp = self.start
        self.start = Node(data)
        self.start.next = temp

    def insert_at(self, data, index):
        if index == 0:
            self.insert_start(data)

        else:
            cur_index = 0
            new_node = Node(data)
            temp = self.start
            while True:
                if cur_index == index:
                    prev_node.next = new_node
                    new_node.next = temp
                    break
                prev_node = temp
                temp = temp.next
                cur_index += 1

    def delete_first(self):
        self.start = self.start.next

    def delete_last(self):
        temp = self.start
        while temp.next is not None:
            temp = temp.next

    def delete_at(self, index):
        cur_index = 0
        cur_node = self.start
        prev_node = None
        while True:
            if cur_index == index:
                prev_node.next = cur_node.next
                break
            prev_node = cur_node
            cur_node = cur_node.next
            cur_index += 1

    def swap(self, data1, data2):
        cur_node = self.start
        prev_node1 = None
        prev_node2 = None
        swap_node1 = Node(data1)
        swap_node2 = Node(data2)
        while True:
            if cur_node.head == data1:
                swap_node1 = cur_node
                break
            prev_node1 = cur_node
            cur_node = cur_node.next
        cur_node = self.start
        while True:
            if cur_node.head == data2:
                swap_node2 = cur_node
                break
            prev_node2 = cur_node
            cur_node = cur_node.next
        prev_node1.next = swap_node2
        next_second = swap_node2.next
        swap_node2.next = swap_node1.next
        prev_node2.next = swap_node1
        swap_node1.next = next_second

    def swap_next(self, prev_node, first_node, second_node):
        first_node.next = second_node.next
        second_node.next = first_node
        if first_node == self.start:
            self.start = second_node
        else:
            prev_node.next = second_node

    def arrange(self):
        # sorting by using array
        temp = self.start
        a = array.array('i')
        i = 0
        while i < self.length():
            a.append(int(temp.head))
            temp = temp.next
            i += 1
        i = 0
        while i < self.length():
            j = 0
            while j < self.length():
                if a[i] > a[j]:
                    temp = a[j]
                    a[j] = a[i]
                    a[i] = temp
                j += 1
            i += 1
        print(a)
        temp = self.start
        i = 0
        while temp is not None:
            temp.head = a[i]
            i += 1
            temp = temp.next

    def sort(self):
        # without using array
        temp = self.start
        prev_node = None
        iterations = self.length() - 1
        while iterations > 0:
            comparisons = iterations
            iterations = iterations - 1
            while comparisons > 0:
                next_node = temp.next
                prev_node = temp
                if temp.head > next_node.head:
                    self.swap_next(prev_node, temp, next_node)
                    temp = temp.next
                else:
                    temp = temp.next
                comparisons = comparisons - 1

    def remove_duplicate(self):
        comparison_node = self.start
        i = 0
        a = array.array('i')
        while i < self.length():
            j = 0
            temp = comparison_node.next
            while j < (self.length()-i-1):
                if comparison_node.head == temp.head:
                    a.append(j)
                temp = temp.next
                j += 1
            comparison_node = comparison_node.next
        p = 0
        while p < len(a):
            self.delete_at(a[p])
            p += 1


def merge_list(list1, list2):
    temp = list1.start
    while temp.next is not None:
        temp = temp.next
    temp.next = list2.start
    list1.view_list()


v1 = 10
v2 = 8
v3 = 15
v4 = 20
v5 = 14
link = LinkedList()
link.insert_last(v1)
link.insert_last(v2)
link.insert_last(v3)
link.insert_last(v4)
link.insert_last(v5)
link.view_list()
print()
print("-------")
len = link.length()
print(len)
print("-------")
link.delete_first()
link.view_list()
print()
v6 = 56
link.insert_start(v6)
link.view_list()
print()
v7 = 2
link.insert_at(v7, 2)
link.view_list()
print()
link.delete_at(2)
link.view_list()
print("-----")
link.swap(8, 20)
link.view_list()
print()

b1 = 2
b2 = 5
b3 = 1
b4 = 7
b5 = 6
b6 = 3
link1 = LinkedList()
link1.insert_last(b1)
link1.insert_last(b2)
link1.insert_last(b3)
link1.insert_last(b4)
link1.insert_last(b5)
link1.insert_last(b6)
link1.view_list()
link1.arrange()
link1.view_list()
#link1.remove_duplicate()
print()
merge_list(link, link1)
print()
print("!!!!!!!!*****!!!!!!!!!")
link.sort()
link.view_list()
