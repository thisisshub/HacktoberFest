graph = {
  '5' : ['3','7'],
  '3' : ['2', '4'],
  '7' : ['8'],
  '2' : [],
  '4' : ['8'],
  '8' : []
}

visited = []
queue = []

def bfs(visited,graph,node):
    queue.append(node)
    visited.append(node)

    while queue:
        ele = queue.pop()
        print(ele,end=" ")

        for neighbour in graph[ele]:
            if neighbour not in visited:
                visited.append(neighbour)
                queue.append(neighbour)

a = bfs(visited, graph, '5')
print(a)
