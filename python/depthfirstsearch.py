class Tree:
    def __init__(self, data=None):
        self.key = data
        self.children = []
 
    def set_root(self, data):
        self.key = data
 
    def add(self, node):
        self.children.append(node)
 
    def search(self, key):
        if self.key == key:
            return self
        for child in self.children:
            temp = child.search(key)
            if temp is not None:
                return temp
        return None
 
    def postorder(self):
        for child in self.children:
            child.postorder()
        print(self.key, end=' ')

tree = None
print('Templates for commands are as follows:(this assumes no duplicate keys)')
print('To add data at root enter:- add <data> at root')
print('To add data below another data enter:- add <data> below <data>')
print('To perform depth-first search traversal using post-order enter:- dfs')
print('To end the process enter:- quit')

while True:
    do = input('What would you like to do? ').split()

    operation = do[0].strip().lower()
    if operation == 'add':
        data = int(do[1])
        new_node = Tree(data)
        suboperation = do[2].strip().lower() 
        if suboperation == 'at':
            tree = new_node
        elif suboperation == 'below':
            position = do[3].strip().lower()
            key = int(position)
            ref_node = None
            if tree is not None:
                ref_node = tree.search(key)
            if ref_node is None:
                print('No such key.')
                continue

    elif operation == 'dfs':
        print('Post-order traversal: ', end='')
        tree.postorder()
        print()
            ref_node.add(new_node)
    elif operation == 'quit':
        break
