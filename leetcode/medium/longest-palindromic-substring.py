class Solution:
    def longestPalindrome(self, s: str) -> str:
        len_s = len(s)

        def is_valid(ss):
            len_ss = len(ss)
            mid = len_ss // 2
            left = ss[0:mid]
            right = (ss[mid + len_ss % 2:])[-1::-1]
            return left == right

        for window in range(len_s, 0, -1):
            for i in range(0, len_s - window + 1):
                ss = s[i:i+window]
                if is_valid(ss):
                    return ss