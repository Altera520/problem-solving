from collections import defaultdict, deque

"""
# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""

class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        graph = defaultdict(list)
        importance = {}
        
        for e in employees:
            graph[e.id] = graph[e.id] + e.subordinates
            importance[e.id] = e.importance
            
        def bfs(st):
            ans = 0
            q = deque([st])
            while q:
                src = q.pop()
                ans += importance[src]
                for dst in graph[src]:
                    q.append(dst)
            return ans
        
        return bfs(id)
                    
                    
