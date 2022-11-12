class Solution:
    def splitMessage(self, message: str, limit: int) -> List[str]:
        M = len(message)
        
        L = [None] * (M + 1)
        for i in range(M + 1):
            L[i] = len(str(i))
        
        left = 0
        right = M
        
        def good(target):
            current = 0
            currentM = M
            
            for i in range(1, target + 1):
                cneeded = 3 + L[i] + L[target]
                
                if limit <= cneeded:
                    return False
                
                used = limit - cneeded
                currentM -= used
                
            if currentM <= 0:
                return True
            return False
        
        while left < right:
            mid = (left + right) // 2
            if good(mid):
                right = mid
            else:
                left = mid + 1
                
                
        part = left     # bcz we return left after binary search      
        ans = []
        print(part)
        i = 0
        for ind in range(1 , part+1):
            extra = limit - (len(str(ind)) + 3 + len(str(part)))
            if extra<=0: return []
            cur = message[i:i+extra] + "<" + str(ind) + "/" + str(part) + ">"
            i = i + extra
            ans.append(cur)
            
        
        return ans