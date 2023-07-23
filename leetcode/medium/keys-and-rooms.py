class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        q = deque([0])
        visit = {}

        while q:
            pt = q.popleft()
            visit[pt] = True
            for room in rooms[pt]:
                if room in visit:
                    continue
                q.append(room)

        return len(visit.keys()) == len(rooms)