class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        d = {}
        n =len(arr)
        c = 0
        if len(arr) % 2 == 1: return False
        for i in range(n):
            x = arr[i]%k
            req = k - x
            if req in d and d[req]>0:
                c+=1
                d[req]-=1
                continue
            
            if x not in d:
                d[x] = 1
            else:
                d[x]+=1
        
        if 0 in d: c+= d[0]//2
        return c==(n//2)