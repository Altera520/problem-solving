class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        st, ed = 0, 0
        tmp = k
        flip = {}
        ans = 0
        v = 0

        for i, num in enumerate(nums):
            
            if num == 1:
                ed = i
                v += 1
            else: # num == 0
                if tmp == 0:
                    for j in range(st, ed + 1):
                        if v > 0:
                            v -= 1
                        if j in flip:
                            del flip[j]
                            st = j + 1
                            tmp += 1
                            break
                if tmp > 0:
                    tmp -= 1
                    v += 1
                    flip[i] = True
                    ed = i
                else:
                    st = i + 1

            ans = max(ans, v)

        return ans

