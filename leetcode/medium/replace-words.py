from collections import defaultdict

class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:        
        d = defaultdict(list)
        for prefix in sorted(dictionary):
            d[prefix[0]].append(prefix)
        
        words = sentence.split()
        
        for idx, word in enumerate(words):
            ch = word[0]
            for prefix in d[ch]:
                if word.startswith(prefix):
                    words[idx] = prefix
                    break
                
        return ' '.join(words)
