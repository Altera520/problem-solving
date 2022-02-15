class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = 0
        left = 0
        used = {}

        for right, char in enumerate(s):
            # 현재문자가 이전에 나왔던 문자이고, 좌측커서가 이전에 나왔던 문자의 위치보다 왼쪽에있다면
            # 좌측커서를 나왔던 문자의 위치 다음 위치로 이동
            if char in used and left <= used[char]:
                left = used[char] + 1
                
            # 처음 나오는 문자라면 window의 길이 계산
            else:
                ans = max(ans, right - left + 1)
                
            # 문자가 나왔던 위치 저장
            used[char] = right

        return ans
