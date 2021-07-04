class Solution:
    def buildArray(self, l: List[int]) -> List[int]:
        n = len(l)
        
    # vis = [0]*n
        ans = [0]*n
        for i in range(n):
            ans[i] = l[l[i]]
        return ans