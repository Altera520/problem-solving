class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        # arr를 chunk로 나눔
        # chunk들을 개별적으로 정렬
        # chunk들을 합치면 전체 arr의 정렬된 값과 같아야 함.
        # 가장 큰 chunk 수

        ans = 0
        sorted_arr = sorted(arr)

        d = {}
        for i in range(len(arr)):
            if arr[i] in d:
                del d[arr[i]]
            else:
                d[arr[i]] = True

            if sorted_arr[i] in d:
                del d[sorted_arr[i]]
            else:
                d[sorted_arr[i]] = True
            
            if len(d) == 0:
                ans += 1
        
        if ans == 0:
            ans = 1
        return ans
