# courtesy : HAPPY CODING! YT


# tc :  O(nlogn) , sc = O(1)
# maintain prev max
'''
class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        ans = 0
        nums.sort()
        prev = nums[0]
        for i in nums:
            if i>prev:
                prev = i+1
            else:
                ans += prev-i
                prev += 1
        return ans
    
'''

'''
[ 3, 2, 1, 2, 1, 7]
sort       : 1 1 2 2 3 7
pos fixing : 1 2 3 4 5 7
ans +=       0 1 1 2 2 0
ans = 6
 
'''   

#Same thing as above, but using counting sort
# tc = O(n), SC = O(n)

class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        ans = 0
        d = [0]*(100001)
        for i in nums:
            d[i]+=1
        
        prev = -1
        ma = max(nums)
        for i in range(ma + 1):
            cnt = d[i]
            
            if cnt>0:
                tot = 0
                maxmove = cnt - 1    # considering prev value does not disturb starting of sequence of same elements
                tot = maxmove*(maxmove+1)//2   # n*(n+1)//2
                maxNum = i + maxmove
                
                # check the base of current number ( or check prev)
                if i<= prev:       # if prev is interfering we have to conisder it also.
                    tot += cnt *(prev - i +1)
                    maxNum += prev - i +1
                ans+= tot  # update answer
                prev = maxNum   # update prev
        return ans