class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        d = Counter()
        for i in arr:
            d[i]+=1
        d =  {k: v for k, v in sorted(d.items(), key=lambda item: item[1])}
        
        ans = len(d)
        s = 0
        for i in d:
            if k<=0:
                break
            p = min(d[i], k)
            d[i]-=p
            k-=p
            if(d[i]==0):
                ans-=1
            else:
                break
    
        return ans