from collections import defaultdict
from queue import PriorityQueue as pq

class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        d = defaultdict(int)
        q = pq()
        for word in words:
            d[word] += 1
        
        for word, order in d.items():
            q.put((-order, word))
        return [q.get()[1] for _ in range(k)]
        
