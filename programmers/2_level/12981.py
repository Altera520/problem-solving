def solution(n, words):
    words = [words[0][0]] + words
    check = {}
    person = 0
    
    for idx, word in enumerate(words[1:]):
        tail = word[0]
        head = words[idx][-1]
        
        if word in check or tail != head:
            return (person % n + 1, (idx + n) // n)
        
        check[word] = True
        person += 1

    return (0, 0)
