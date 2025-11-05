from collections import defaultdict

class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        tmp = defaultdict(int)
        d = {}
        ages = sorted(ages)
        predicate = lambda x,y: y <= 0.5 * x + 7

        for age in ages:
            tmp[age] += 1
        for k, v in tmp.items():
            if v > 1 and not predicate(k, k):
                d[k] = v

        ans = 0
        y = 0

        for x, age in enumerate(ages):
            # find y
            for _y in range(y, x):
                if predicate(age, ages[_y]):
                    y += 1
                else:
                    break

            if x != y:
                ans += len(ages[y:x])
            if age in d:
                ans += d[age] - 1
                d[age] -= 1
         
        return ans


