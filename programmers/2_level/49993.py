def solution(skill, skill_trees):
    answer = 0
    
    for tree in skill_trees:
        skill_subset = ''.join([ch for ch in tree if ch in skill])
        
        if skill.startswith(skill_subset):
            answer+=1
            
    return answer

"""
from collections import deque


def solution(skill, skill_trees):
    answer = 0

    for seq in skill_trees:
        dq = deque(skill)

        for ch in seq:
            if ch in skill and ch != dq.popleft():
                break
        else:
            answer += 1

    return answer
"""
