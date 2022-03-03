from collections import defaultdict
import re


def processing(str):
    str = str.lower()
    dic = defaultdict(int)
    pat = re.compile('[a-z]{2}')
    
    for index in range(0, len(str) - 1):
        substr = str[index: index + 2]
        
        if not pat.match(substr):
            continue
            
        dic[substr] += 1
        
    return dic


def join(src, target):
    intersect = 0
    union = 0
    
    for k, v in src.items():
        intersect += min(target[k], v)
        target[k] = max(target[k], v)
        
    for k, v in target.items():
        union += v
    
    if intersect + union == 0:
        intersect = 1
        union = 1
    
    return intersect, union


def solution(str1, str2):
    intersect, union = join(processing(str1), processing(str2))
    
    return int((intersect / union) * 65536)
