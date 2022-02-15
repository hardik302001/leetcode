class Solution:
    def reachNumber(self, target: int) -> int:
        
        target = abs(target)        
        cur = 1
        while target>0:
            target = target - cur
            if target==0:
                return cur 
            cur = cur + 1
                
        if abs(target)%2==0:
            return cur-1
        else:
            return cur if cur&1 else cur + 1 
