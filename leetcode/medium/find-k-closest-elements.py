class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:

        def _closest(a, b, x):
            abs_a = abs(a - x)
            abs_b = abs(b - x)

            if abs_a < abs_b:
                return a
            elif abs_a == abs_b:
                return min(a, b)
            else:
                return b
        
        def _binary_search(arr, x):
            low = 0
            high = len(arr) - 1
            mid = 0

            while low <= high:
                mid = (high + low) // 2
                if arr[mid] < x:
                    low = mid + 1
                elif arr[mid] > x:
                    high = mid - 1
                else:
                    return mid
            return low

        index = _binary_search(arr, x)

        st = max(index - k, 0)
        ed = min(index + k, len(arr))

        while True:
            if st + k >= ed or _closest(arr[st], arr[st + k], x) == arr[st]:
                return arr[st : st + k]
            st += 1
