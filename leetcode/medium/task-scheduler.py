from collections import defaultdict, deque
from queue import PriorityQueue

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        d = defaultdict(int)
        pq = PriorityQueue()
        q = deque() 
        ans = 0
        seq = 0

        for task in tasks:
            d[task] += 1

        for k, v in d.items():
            pq.put((v * -1, k))
            
        while True:
            if seq == 0 and q:
                while q:
                    pq.put(q.popleft())
            if pq.empty() and q:
                if seq:
                    ans += ((n + 1) - seq)
                    seq = 0
                while q:
                    pq.put(q.popleft())
                continue
            if pq.empty() and not q:
                break
            ans += 1

            v, task = pq.get()
            v += 1
            print(ans,seq,task)

            if v:
                q.append((v, task))
            seq += 1
            seq %= (n + 1)

        return ans
