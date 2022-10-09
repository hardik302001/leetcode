class Solution:
    def findArray(self, pref: List[int]) -> List[int]:
        ans = pref[:]
        n = len(pref)
        
        for i in range(1, n):
            ans[i] = pref[i-1]^pref[i]
        return ans