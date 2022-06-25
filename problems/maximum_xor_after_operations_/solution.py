class Solution:
    def maximumXOR(self, nums: List[int]) -> int:
        c = 0
        ans = 0
        for i in range(31 , -1 , -1):
            c = 0
            for n in nums:
                if n&(1<<i):
                    c+=1
            if c==0:
                continue
            elif c&1:
                ans+=(1<<i)
            else:
                c-=1
                if c==0:
                    continue
                ans+=(1<<i)
        return ans
                
                