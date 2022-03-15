dic = "AEIOU"
count = 0

def search(word, target):
    global count
    
    if word == target:
        return count
    
    if len(word) == len(dic):
        return -1
    
    for ch in dic:
        word.append(ch)
        count += 1
        
        result = search(word, target)
        if result != -1:
            break
            
        word.pop()
        
    return result
    

def solution(word):
    return search([], list(word))
