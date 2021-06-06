class Solution:
    def reductionOperations(self, nums: List[int]) -> int:
        d = {}
        for i in nums:
            if i in d:
                d[i] +=1
            else:
                d[i] =1 

        ans = 0
        d = (sorted(d.items()))
        out = []
        for tup in d:
            out.append([tup[0],tup[1]])

        d = out
        if len(d)==1:
            return ans
        ln = len(d)

        for i in range(ln-1,-1,-1):
            ans = ans + d[i][1]*i
            if i==0:
                break

        return ans
        
        