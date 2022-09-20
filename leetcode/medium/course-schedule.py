class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = defaultdict(list)
        indegree = {}
        
        def f(arg):
            if arg not in indegree:
                indegree[arg] = 0
        
        for pair in prerequisites:
            src, dst = tuple(pair)
            graph[src].append(dst)
            f(src)
            f(dst)
            indegree[dst] += 1
        
        q = deque()
        for k, v in indegree.items():
            if v == 0:
                q.append(k)
        
        while q:
            k = q.popleft()
            for dst in graph[k]:
                indegree[dst] -= 1
                if indegree[dst] == 0:
                    q.append(dst)
        
        return len([v for v in indegree.values() if v != 0]) == 0
