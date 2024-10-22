class Solution:
    def shiftingLetters(self, s: str, shifts: List[int]) -> str:
        for i in range(len(shifts) - 2, -1, -1):
            shifts[i] += shifts[i + 1]

        d = [chr(alphabet) for alphabet in range(ord('a'), ord('z') + 1)]
        l = len(d)

        ans = ''
        for i, shifts in enumerate(shifts):
            ans += d[(ord(s[i]) - ord('a') + shifts) % 1]
        return ans
