class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        
        shouldBe = n%2
        while n>0:
            p = n%2
            if p != shouldBe:
                return False
            
            shouldBe = 1^p
            n= n//2
        
        return True