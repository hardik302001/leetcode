'''
https://leetcode.com/problems/basic-calculator/discuss/1456850/Python-Basic-Calculator-I-II-III-easy-solution-detailed-explanation
'''

'''
# also see https://leetcode.com/problems/basic-calculator-ii/discuss/1646045/python-simple-one-pass-on-solution-stack-clean-and-easy-to-understand-explained

'''



# This algorithm works for Basic Calculator (BC I) problem, where we can have only + - ( ) operations, for Basic Calculator II (BC II), where we can have only + - * / operations and also for Basic Calculator III (BC III), where we can have all + - * / ( ) operations.

# Stack of monomials
# The idea is to use both stack and recursion (which can be seen as 2 stack, because recursion use implicit stack). First, let us consider, that we do not have any brackets. Then let us keep the stack of monomial, consider the example s = 1*2 - 3\4*5 + 6. Then we want our stack to be equal to [1*2, -3\4*5, 6], let us do it step by step:

# Put 1 into stack, we have stack = [1].
# We can see that operation is equal to *, so we pop the last element from our stack and put new element: 1*2, now stack = [1*2].
# Now, operation is equal to -, so we put -3 to stack and we have stack = [1*2, -3] now
# Now, operation is equal to \, so we pop the last element from stack and put -3\4 instead, stack = [1*2, -3\4]
# Now, operation is equal to *, so we pop last element from stack and put -3\4*5 instead, stack = [1*2, -3\4*5].
# Finally, operation is equal to +, so we put 6 to stack: stack = [1*2, -3\4*5, 6]
# Now, all we need to do is to return sum of all elements in stack.

# How to deal with brackets
# If we want to be able to process the brackets properly, all we need to do is to call our calculator recursively! When we see the open bracket (, we call calculator with the rest of our string, and when we see closed bracket ')', we give back the value of expression inside brackets and the place where we need to start when we go out of recursion.

# Complexity
# Even though we have stack and also have recursion, we process every element only once, so time complexity is O(n). However we pass slice of string as argument each time we meet bracket, so time complexity can go upto O(n^2) on example like (1+(1+(... +))) with O(n) open brackets. Space complexity is potentially O(n), because we need to keep stacks, but each element not more than once.

# class Solution:
#     def calculate(self, s):
#         def update(op, v):
#             if op == "+": stack.append(v)
#             if op == "-": stack.append(-v)
#             if op == "*": stack.append(stack.pop() * v)           #for BC II and BC III
#             if op == "/": stack.append(int(stack.pop() / v))      #for BC II and BC III
    
#         it, num, stack, sign = 0, 0, [], "+"
        
#         while it < len(s):
#             if s[it].isdigit():
#                 num = num * 10 + int(s[it])
#             elif s[it] in "+-*/":
#                 update(sign, num)
#                 num, sign = 0, s[it]
#             elif s[it] == "(":                                        # For BC I and BC III
#                 num, j = self.calculate(s[it + 1:])
#                 it = it + j
#             elif s[it] == ")":                                        # For BC I and BC III
#                 update(sign, num)
#                 return sum(stack), it + 1
#             it += 1
#         update(sign, num)
#         return sum(stack)
# Solution 2
# The problem of previous code is that we pass slice of string as parameter. In python it works quite fast, because function is implemented in C and it works very fast. If we want to have honest linear time, we need to pass index as parameter. (there is alternative way like I used in problem 1896 https://leetcode.com/problems/minimum-cost-to-change-the-final-value-of-expression/discuss/1267304/Python-Recursion-dfs-solution-explained, where we can precalculate pairs of open and closing brackets)

# Complexity
# Now time complexity it is O(n), space is still O(n).

# Code

#the same code can be used for BASIC CALC 1, 2 , 3
class Solution:
    def calculate(self, s):    
        def calc(it):
            def update(op, v):
                if op == "+": stack.append(v)
                if op == "-": stack.append(-v)
                if op == "*": stack.append(stack.pop() * v)
                if op == "/": stack.append(int(stack.pop() / v))
            num, stack, sign = 0, [], "+"
            
            while it < len(s):
                if s[it].isdigit():
                    num = num * 10 + int(s[it])
                elif s[it] in "+-*/":
                    update(sign, num)
                    num, sign = 0, s[it]
                elif s[it] == "(":
                    num, j = calc(it + 1)
                    it = j   # bcz we will do it+=1 at end anyways
                elif s[it] == ")":
                    update(sign, num)
                    return sum(stack), it         #here we are returning 2 variables
                it += 1
            update(sign, num)    # what if there are no brackets
            return sum(stack)
        return calc(0)