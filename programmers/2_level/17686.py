from functools import cmp_to_key
import re

head = re.compile('[a-z- .]+')
number = re.compile('\d+')


def part(pat, val):
    return pat.search(val).group(0)


def cmp(val1, val2):
    if val1 == val2:
        return None
    return 1 if val1 > val2 else -1


def custom_sort(val1, val2):
    val1 = val1.lower()
    val2 = val2.lower()
    parts = [
        (part(head, val1), part(head, val2)),
        (int(part(number, val1)), int(part(number, val2)))
    ]
    
    for p in parts:
        res = cmp(*p)        
        if res:
            return res
    return 0


def solution(files):
    return sorted(files, key=cmp_to_key(custom_sort))
