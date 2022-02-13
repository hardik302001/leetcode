class Solution:
    def countOperations(self, num1: int, num2: int) -> int:
        ans = 0
        if num1==0 or num2==0:
            return 0
        elif num1==num2:
            return 1
        
        while num1!=num2 or num1!=1 or num2!=1:
            if num1>num2:
                x = (num1)//num2
                
                ans = ans + x
                num1 = num1 - (x)*num2
                
                num1, num2 = num2 , num1
            else:
                x = (num2)//num1
                
                ans = ans + x
                num2 = num2 - (x)*num1
                
                num2, num1 = num1 , num2
                
            if num1==1:
                return ( ans + num2)
            elif num2==1:
                return ans + num1
            elif num1==0 or num2==0:
                return ans
                
            
        
        return ans +1
            