def solution(s):
    def compress(binary):
        digit = len([b for b in binary if b == '1'])
        return digit, len(binary) - digit
    to_binary = lambda num: "{0:b}".format(num)
    step = 0
    remove = 0
    
    while s != '1':
        step += 1
        tmp = compress(s)
        remove += tmp[1]
        s = to_binary(tmp[0])
        
    return step, remove
        
