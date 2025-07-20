class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:

        def to_int(hhmm):
            if hhmm == '00:00':
                hhmm = '24:00'
            hh, mm = tuple(hhmm.split(':'))
            return int(hh) * 60 + int(mm)

        points = []
        tmp = []
        for point in timePoints:
            points.append(to_int(point))
        
        points.sort()
        points.append(points[0] + 24 * 60)

        for i in range(len(points) - 1):
            tmp.append(abs(points[i] - points[i + 1]))  
        return min(tmp)
        
