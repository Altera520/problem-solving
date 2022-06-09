import math

class Solution:
    def fractionAddition(self, expression: str) -> str:
        if expression[0] != '-':
            expression = '+' + expression
        expr = []
        pat = re.compile('[-|+]{0,1}[0-9]*/[0-9]*')
        for s in pat.findall(expression):
            symbol = 1 if s[0] == '+' else -1
            s = s.replace(s[0], '').split('/')
            expr.append((symbol, int(s[0]), int(s[1])))
            
        def calc(v1, v2):
            lcm = math.lcm(v1[2], v2[2])
            conv = lambda v: lcm // v[2] * v[1] * v[0]
            res = conv(v1) + conv(v2)
            
            gcd = math.gcd(res, lcm)
            res = res // gcd
            lcm = lcm // gcd
            
            return (1, 0, 1) if res == 0 else (-1 if res < 0 else 1, abs(res), lcm)
        
        ans = expr[0]
        for e in expr[1:]:
            ans = calc(ans, e)
        
        return ''.join(['-' if ans[0] == -1 else '', str(ans[1]), '/', str(ans[2])])
            
