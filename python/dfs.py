from collections import defaultdict
class Graph:
    def  __init__(self):
        self.graph = defaultdict(list)
        
    def addEdge(self,u,v):
        self.graph[u].append(v)
    
    def DFS(self,start):
        visited = [False]*(max(self.graph)+1)
        queue=[]
        queue.append(start)
        visited[start]=True
        
        while(queue):
            start = queue.pop()
            print(start,end=" ")

            for i in self.graph[start]:
                if visited[i] == False:
                    queue.append(i)
                    visited[i]=True
                    
    
g = Graph()
g.addEdge(0,1)
g.addEdge(0,2)
g.addEdge(1,2)
g.addEdge(2,0)
g.addEdge(2,3)
g.addEdge(3,3)

print("Depth first traversal")

g.DFS(2)      
