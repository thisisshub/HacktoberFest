class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        visited = set()
        numofIsland = 0
        for i in stones:
            if tuple(i) not in visited:
                self.dfs(i,visited,stones)
                numofIsland +=1
        return len(stones) - numofIsland
    
    def dfs(self,i,visited,stones):
        visited.add(tuple(i))
        for j in stones:
            if tuple(j) not in visited:
                if i[0] == j[0] or i[1]==j[1]:
                    self.dfs(j,visited,stones)
