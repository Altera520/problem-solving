from collections import defaultdict as dd
from queue import PriorityQueue as pq

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        d = dd(int)
        for num in nums:
            d[num] += 1
        
        q = pq()
        for num, order in d.items():
            q.put((-order, num))
            
        return [q.get()[1] for _ in range(k)]
            
            
