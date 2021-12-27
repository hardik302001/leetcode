# noce ques, really took me time to do this!
# try solving some test cases

# similar to this : https://leetcode.com/problems/array-of-doubled-pairs/


class Solution:
    def recoverArray(self, nums: List[int]) -> List[int]:
        
        
        def check(nums, k):
            d = {}
            arr = []
            # print("k ",k)
            for i in nums:
                if (i - 2*k) in d and d[i - 2*k]>0:
                    d[i- 2*k ] -=1
                    arr.append(i-k)
                    # print(i)
                    continue
                if i in d:
                    d[i]+=1
                else:
                    d[i] = 1
                    
            if len(arr)==(len(nums)//2):
                return ( True, arr )
            return ( False, [] )
        
        
        
        
        nums.sort()
        # it is sure that nums[0] = arr[i] -k and nums[-1] = arr[i]+k, for some valid i
        n =len(nums)
        beg = nums[0]
        for i in range(1, n):
            diff = nums[i] - beg
            if diff & 1 or diff==0:
                continue
            else:
                k = diff//2
                res , arr = check(nums, k)
                if res==False:
                    continue
                else:
                    return arr