class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        d = {}
        n = len(nums)
        for i in range(n):
            for j in range(i+1,n):
                p = nums[i]*nums[j]
                if p in d:
                    d[p]+=1
                else:
                    d[p] = 1
        ans = 0
        print(d)
        for i in d:
            ans = ans + d[i]*(d[i]-1)
        
        return ans*4   # 4 possible permutations