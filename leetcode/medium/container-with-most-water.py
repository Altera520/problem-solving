class Solution:
    def maxArea(self, height: List[int]) -> int:
        st = 0
        ed = len(height) - 1
        ans = 0

        while st != ed:
            h = min(height[st], height[ed])
            ans = max((ed - st) * h, ans)

            if height[st] < height[ed]:
                st += 1
            else:
                ed -= 1

        return ans