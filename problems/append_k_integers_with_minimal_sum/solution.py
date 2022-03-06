class Solution:
    def minimalKSum(self, nums: List[int], k: int) -> int:
        ans = 0
        nums.sort()
        if nums[0]!=1:
            nums = [1] + nums
            k-=1
            ans += 1
        # print(nums)
        n = len(nums)
        for i in range(1 , n):
            prev = nums[i-1]
            cur = nums[i]
            
            dif = cur - prev-1
            if dif>0:
                if dif<=k:
                    s = cur*(cur-1)//2 - prev*(prev+1)//2
                    # print(prev, cur, s)
                    ans = ans + s
                    k = k - dif
                else:
                    cur = prev + k +1
                    dif = cur - prev-1
                    s = cur*(cur-1)//2 - prev*(prev+1)//2
                    # print(prev , cur , s)
                    ans = ans + s
                    k = k - dif
            if k==0:
                return ans
            
            
        if k>0:
            prev = nums[-1]
            cur = prev + k +1
            dif = cur - prev-1
            s = cur*(cur-1)//2 - prev*(prev+1)//2
            ans = ans + s
        return ans   
                