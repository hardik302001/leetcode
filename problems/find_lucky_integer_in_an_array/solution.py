class Solution:
    def findLucky(self, arr: List[int]) -> int:
        d ={}
        for i in arr:
            if i in d:
                d[i]+=1
            else:
                d[i] =1 
        res = [-1]
        for i in d:
            if d[i]==i:
                res.append(i)
        return max(res)