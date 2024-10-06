class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        predicates = [
            lambda k: arr[k] > arr[k + 1],
            lambda k: arr[k] < arr[k + 1],
        ]

        def _turbulent(seed):
            ans = 0 
            count = 1
            for k in range(0, len(arr) - 1):
                if predicates[seed](k):
                    count += 1
                else:
                    ans = max(ans, count)
                    count = 1
                seed = abs(seed - 1)
            return max(ans, count)
        
        return max(_turbulent(0), _turbulent(1))
