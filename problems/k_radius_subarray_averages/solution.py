class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        sz = 2*k+1
        ans = [-1]*n
        
        l = 0
        s = 0
        
        for r in range(n):
            s = s + nums[r]
            # print(l,r,s)
            if (r-l+1)==sz:
                m = l + sz//2
                x = s//sz
                # print(x)
                ans[m] = s//sz
                s = s- nums[l]
                l = l +1
            
        return ans
                