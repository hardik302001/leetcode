import math
class Solution:
    def closestPrimes(self, low: int, high: int) -> List[int]:
        prime = [True]*(high+1)
        prime[1]= False
        for i in range(2, int(high**(0.5))+1):
            if prime[i]:
                cur = i
                cur = cur + i
                while cur<=high:
                    prime[cur] = False
                    cur = cur + i
        pr = []
        for i in range(low , high+1):
            if prime[i]:
                pr.append(i)  

        
        mi = 10**12
        p = -1
        ans = [-1, -1]
    
        for k in pr:
            if p==-1:
                p = k
            else:
                if (k-p)<mi:
                    mi = min(mi , k-p)
                    ans = [p , k]
                p = k
        return ans