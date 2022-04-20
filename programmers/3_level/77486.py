from collections import defaultdict as dd, deque
from functools import reduce
import math


def topology_sort(enroll, edge, indegree, benefit):
    q = deque([name for name in enroll if indegree[name] == 0])

    while q:
        child = q.popleft()
        parent = edge[child]
        
        for idx, value in enumerate(benefit[child]):
            repayment = value / 10
            if repayment >= 1:
                repayment = math.floor(repayment)
                benefit[child][idx] -= repayment
                benefit[parent].append(repayment)
        
        indegree[parent] -= 1
        if indegree[parent] == 0 and parent != '-':
            q.append(parent)
    return benefit
                


def solution(enroll, referral, seller, amount):
    edge = {}
    benefit = dd(list)
    indegree = dd(int)
    
    for i, name in enumerate(seller):
        benefit[name].append(amount[i] * 100)
        
    for i, ref in enumerate(referral):
        edge[enroll[i]] = ref
        indegree[ref] += 1
    
    benefit = topology_sort(enroll, edge, indegree, benefit)
    
    return [reduce(lambda acc, cur: acc + cur, benefit[name], 0) for name in enroll]
