import re

def minimum_result(digit, op_list, flag):
    ans = digit[0]
    for i, op in enumerate(op_list):
        flag = flag or op == '-'
        ans += digit[i + 1] * (-1 if flag else 1)
    return ans


def solution():
    expr = input()
    raw_digit = re.split('\+|\-', expr)

    flag = expr[0] == '-'
    if flag:
        raw_digit[0] = '0'

    digit = list(map(int, raw_digit))
    op_list = [exp for exp in expr if exp < '0']

    print(minimum_result(digit, op_list, flag))


if __name__ == '__main__':
    solution()