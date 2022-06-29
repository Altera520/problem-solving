class Solution:
    def busyStudent(self, startTime: List[int], endTime: List[int], queryTime: int) -> int:
        return len([st for st, ed in zip(startTime, endTime) if st <= queryTime <= ed])
