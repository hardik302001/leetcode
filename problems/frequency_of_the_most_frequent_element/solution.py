# Complexity:

# Time: O(NlogN)
# Space: O(N)
# Python 3

class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        n = len(nums)
        nums.sort()
        preSum = [0] * (n + 1)
        for i in range(n):
            preSum[i + 1] = preSum[i] + nums[i]

        def getSum(left, right):  # left, right inclusive
            return preSum[right + 1] - preSum[left]

        def count(index): # Count frequency of `nums[index]`in range [ 0 , index ] if we make other elements equal to `nums[index]`
            left = 0
            right = index
            res = index
            while left < right:
                mid = left + (right - left) // 2
                s = getSum(mid, index - 1) # get sum of (nums[mid], nums[mid+1]...nums[index-1])
                if  k >= ((index - mid) * nums[index] - s): # Found an answer -> Try to find a better answer in the left side
                    right = mid
                else:
                    left = mid + 1
                    
            return index - left + 1

        ans = 0
        for i in range(n):
            ans = max(ans, count(i))
        return ans