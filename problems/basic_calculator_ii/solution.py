# idea : https://leetcode.com/problems/basic-calculator/

class Solution:
    def calculate(self, s):    
        def update(op, v):
            if op == "+": stack.append(v)
            if op == "-": stack.append(-v)
            if op == "*": stack.append(stack.pop() * v)
            if op == "/": stack.append(int(stack.pop() / v))

        num, stack, sign , it = 0, [], "+" , 0

        while it < len(s):
            if s[it].isdigit():
                num = num * 10 + int(s[it])
            elif s[it] in "+-*/":
                update(sign, num)  # this sign is previous sign
                num, sign = 0, s[it]
            it += 1
           
        update(sign, num)
        return sum(stack)
