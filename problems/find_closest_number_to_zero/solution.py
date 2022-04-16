class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        p = []
        for i in nums:
            p.append([abs(i) , i])
        p.sort()
        
        ans = p[0][0]
        m = p[0][1]
        for i in p:
            if(i[0]==ans):
                m = max( m , i[1])
            else:
                break
        return m
            