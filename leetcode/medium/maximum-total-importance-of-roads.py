from collections import defaultdict as dd
from queue import PriorityQueue as pq

class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        graph = dd(int)
        for road in roads:
            src, dst = tuple(road)
            graph[src] += 1
            graph[dst] += 1
        
        order = {}
        q = pq() 
        for k, v in graph.items():
            q.put((-v, k))
        
        while not q.empty():
            _, k = q.get()
            order[k] = n
            n -= 1
        
        ans = 0
        for road in roads:
            src, dst = tuple(road)
            ans += (order[src] + order[dst])
        return ans
        
