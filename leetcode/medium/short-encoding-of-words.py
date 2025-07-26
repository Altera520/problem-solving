class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        d = {}

        words = set(words)
        for word in words:
            for i in range(1, len(word)):
                d[word[i:]] = True

        ans = []
        for word in words:
            if word not in d:
                ans.append(len(word))

        return sum(ans) + len(ans)