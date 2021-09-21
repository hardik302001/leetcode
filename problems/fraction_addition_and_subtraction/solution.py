# very similar to solve the equation leetcode


class Solution:
    def fractionAddition(self, expression: str) -> str:
            
        lst = expression.replace("+", " +").replace("-", " -").split()
        # print(lst)
        A, B = 0, 1
        for num in lst:
            a, b = map(int , num.split("/"))   #now we dont need to take care of sign
            B *= b
            
        for num in lst:
            a, b = map(int , num.split("/"))   #now we dont need to take care of sign
            A = A + a*(B//b)
            
            
        devisor = gcd(A, B)
        A //= devisor; B //= devisor
        return str(A) + "/" + str(B)