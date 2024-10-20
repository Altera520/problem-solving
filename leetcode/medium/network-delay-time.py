import math
from queue import PriorityQueue
from collections import defaultdict, namedtuple

Node = namedtuple('Node', ['weight', 'no'])

class Dijkstra:

    def __init__(self, size):
        self.distance = [math.inf for _ in range(size + 1)]
        self.pq = PriorityQueue()
        self.graph = defaultdict(list)

    def travel(self, start):
        if start not in self.graph:
            return

        self.distance[start] = 0
        self.pq.put(Node(0, start))

        while not self.pq.empty():
            cur = self.pq.get()
            # 최단거리가 가중치보다 작으면 수행 X
            if self.distance[cur.no] < cur.weight:
                continue 
            
            for _next in self.graph[cur.no]:
                weight = _next.weight + cur.weight

                # 더 짧은 거리라면 갱신
                if weight < self.distance[_next.no]:
                    self.distance[_next.no] = weight
                    self.pq.put(Node(weight, _next.no))


class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        d = Dijkstra(n)

        for time in times:
            src, dst, weight = tuple(time)
            d.graph[src].append(Node(weight, dst))

        d.travel(k)
        for w in d.distance[1:]:
            # n개 노드 중 신호를 수진하지 못한 케이스(INF)가 있다면
            if w == math.inf:
                return -1
        return max(d.distance[1:])