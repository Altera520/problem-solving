class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.strip().split(' ')
        return ' '.join([word for word in s[::-1] if word])