import math
class Solution:
    def isReachable(self, x: int, y: int) -> bool:
        while x%2==0:
            x=x//2
        while y%2==0:
            y = y//2
        
      
        
        gc = math.gcd(x, y)
        
        return gc==1
            