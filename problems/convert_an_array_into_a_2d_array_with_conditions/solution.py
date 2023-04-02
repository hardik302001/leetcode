class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        d = Counter(nums)
        row = 0
        for i in d:
            row = max(row, d[i])
        ans = []
        
        while row>0:
            t = []
            for i in d:
                if d[i]==0: continue
                else: 
                    t.append(i)
                    d[i]-=1
            ans.append(t)
            row-=1
        return ans