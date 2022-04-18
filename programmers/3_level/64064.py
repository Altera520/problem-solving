import re
from functools import reduce

answer = {}

def dfs(blacklist, depth = 0, temp = []):
    if len(blacklist) == depth:
        answer[tuple(sorted(temp[:]))] = 1
        return
    
    for user in blacklist[depth]:
        if user not in temp:
            temp.append(user)
            dfs(blacklist, depth + 1, temp)
            temp.pop()
        

def solution(user_id, banned_id):
    blacklist = []
    
    patterns = [re.compile(id.replace('*', '\w')) for id in banned_id]
        
    for pattern in patterns:
        blacklist.append([user for user in user_id if pattern.fullmatch(user) is not None])
        
    dfs(blacklist)
        
    return len(answer.keys())
