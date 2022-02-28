from queue import PriorityQueue
from collections import defaultdict
import re

EMPTY = ''

def solution(s):
    tuple = []
    answer = []
    p = re.compile('[0-9]+')
    
    for raw in s.split('},'):
        tmp = p.findall(raw)
        tuple.append(map(int, tmp))
    
    pq = PriorityQueue()
    count = defaultdict(int)
    for subset in tuple:
        for item in subset:
            count[item] += 1
            
    for k, v in count.items():
        pq.put((-v, k))
        
    while not pq.empty():
        k, v = pq.get()
        answer.append(v)
    
    return answer
