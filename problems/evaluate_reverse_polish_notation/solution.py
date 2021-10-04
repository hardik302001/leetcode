class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for i in tokens:
            if i=='+':
                p = stack.pop()
                q = stack.pop()
                res = p + q
                stack.append(res)
            elif i=='-':
                p = stack.pop()
                q = stack.pop()
                res = q - p
                stack.append(res)
            elif i=='*':
                p = stack.pop()
                q = stack.pop()
                res = p * q
                stack.append(res)
            elif i=='/':
                p = stack.pop()
                q = stack.pop()
                if p*q>=0:
                    f = 1
                else:
                    f = -1

                res = f * (abs(q)//abs(p))
                
                stack.append(res)
            else:
                stack.append(int(i))
            # print(stack)
        return stack[0]
                
'''
Note that division between two integers should truncate toward zero.

["6","7","/"]
["-6","7","/"]
["6","-7","/"]
["-6","-7","/"]
["7","6","/"]
["-7","6","/"]
["7","-6","/"]
["-7","-6","/"]

OUTPUT : 
0
0
0
0
1
-1
-1
1


'''