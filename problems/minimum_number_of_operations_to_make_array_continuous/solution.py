'''
Like in the first sample test case, nums = [4,2,5,3],
let n = nums.size()
so we will first check from indexes 1 to n , count of ( if index exist in nums )
then from 2 to n+1
then 3 to n+2
.
.
and so on till 1000000000-n+1 to 1000000000
why between 1 to n  or 2 to n+1....
bcz 1 to n have size n, and max-min = n-1, so we have n elements and we need max-min = n-1, so both conditions are satisfied
then take max of count for each window,
and then return n - (max of count)
but in this way we get tle, this is O(n2)
see previous soln for tle codes



Rather than fixing size and checking if index exist in nums, we will do it the other way

we will take eleemnts directly from nums(it means those elements exist in nums) and check this differnce between them is n-1..

the case of repated elements can be handled easily, and repeated elements need to be replaced, so we will consider set, and a sorted set, so that it is easily to take difference

'''

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        x = n-1
        m = 0           #gives number of elements existing in range of [i, i+n] in nums, so we need to replace n-m eleemnts to make it continuous
        r = 0
        nums = sorted(set(nums))
        newn = len(nums)
        
        for l in range(newn):
            while r+1<newn and nums[r+1]-nums[l] <= x:    #update r until we have difference less than x
                r = r +1
            m = max(m, (r+1)-l)
            
            
        return n-m
            

