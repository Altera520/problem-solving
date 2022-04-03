def solution(s):
    answer = []
    for word in s.split(' '):
        if len(word) == 0:
            answer.append('')
            continue
        tmp = list(word.lower())
        tmp[0] = tmp[0].upper()
        answer.append(''.join(tmp))
    
    return ' '.join(answer)
