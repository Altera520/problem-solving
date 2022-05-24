from queue import PriorityQueue

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        pos_neg = lambda x: x * -1
        pq = PriorityQueue()
        for num in nums:
            pq.put(pos_neg(num))
            
        for _ in range(0, k):
            ans = pq.get()
        return pos_neg(ans)
                
