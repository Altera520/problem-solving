from queue import PriorityQueue as pq

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        q = pq()
        
        for point in points:
            x, y = tuple(point)
            distance = math.sqrt(abs(x) ** 2 + abs(y) ** 2)
            q.put((distance, point))
            
        return [q.get()[1] for _ in range(k)]
