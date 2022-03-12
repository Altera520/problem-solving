from collections import deque, defaultdict
import re


def solution(begin, target, words):
    q = deque([(begin, 0)])
    visit = defaultdict(bool)
    
    while q:
        current, step = q.popleft()
        if current == target:
            return step
        
        for idx, _ in enumerate(current):
            mask_word = list(current)
            mask_word[idx] = '[a-z]'
            pattern = re.compile(''.join(mask_word))
        
            for word in words:
                if current == word or visit[word]:
                    continue
                
                if pattern.match(word):
                    visit[word] = True
                    q.append((word, step + 1))
    return 0
