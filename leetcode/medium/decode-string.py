class Solution:
    def to_infix(self, s):
        infix = []
        digit = ''

        for ch in s:
            if ch.isdigit():
                digit += ch
            else:
                if digit:
                    if infix and infix[-1] != '(':
                        infix.append('+')
                    infix.append(digit)
                    digit = ''
                if ch == '[':
                    if infix and infix[-1].isdigit():
                        infix.append('*')
                    elif infix:
                        infix.append('+')
                    infix.append('(')
                elif ch == ']':
                    infix.append(')')
                else:
                    if infix and (('a' <= infix[-1] <= 'z') or infix[-1] == ')'):
                        infix.append('+')
                    infix.append(ch)
        return infix

    def to_postfix(self, infix):
        precedence = {'+': 1, '*': 2}
        stack = []
        output = []

        for token in infix:
            if token not in ('+', '*', '(', ')'): # operand
                output.append(token)
            elif token == '(':
                stack.append(token)
            elif token == ')':
                while stack and stack[-1] != '(':
                    output.append(stack.pop())
                stack.pop()
            else: # 연산자
                while (stack and stack[-1] != '(' and
                       precedence.get(token, 0) <= precedence.get(stack[-1], 0)):
                    output.append(stack.pop())
                stack.append(token)

        while stack:
            output.append(stack.pop())
        return output

    def evaluate(self, postfix):
        stack = []

        for token in postfix:
            if token not in ('+', '*'):
                if token.isdigit():
                    token = int(token)
                stack.append(token)
            else:
                b = stack.pop()
                a = stack.pop()
                if token == '+':
                    result = a + b
                elif token == '*':
                    result = a * b
                stack.append(result)

        return stack[0] if stack else None

    def decodeString(self, s: str) -> str:
        infix = self.to_infix(s)
        postfix = self.to_postfix(infix)
        ans = self.evaluate(postfix)

        return ans
