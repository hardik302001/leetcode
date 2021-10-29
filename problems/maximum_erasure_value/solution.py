#exactly same as : https://leetcode.com/problems/longest-substring-without-repeating-characters/         cpp soln
#we consider sum here, rather than size of subarray



class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        l = 0
        m = 0
        d = {}     #d[x]==1 -> prsent  , d[x]==0  -> absent
        s = 0
        n = len(nums)
        for r in range(n):
            cur = nums[r]
            if cur not in d or d[cur]==0:
                d[cur] = 1
                s = s + nums[r]
            else:                 #key exist and d[key]>0(presemnt) also
                while nums[l]!=cur:
                    d[nums[l]]= 0
                    s = s - nums[l]
                    l = l + 1
                 
                s = s - nums[l]
                l = l +1
                s = s + nums[r]
                
            m = max(m, s)
            
        return m
            