# graph theory
# make a dictionaries of all the nodes(vertices) and their linked nodes in the unordered graph
from collections import defaultdict

graph = defaultdict(list)
v,e = map(int,input().split())
# v -> no. of vertices
# e -> no. of edges
for i in range(e):
    u, v = input().split()
    graph[u].append(v)
    graph[v].append(u)
for i in graph:
    print(i,graph[i])
