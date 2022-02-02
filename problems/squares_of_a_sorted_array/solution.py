# one thing to notice here is that array can have multiple occurence of any element

# O(nlogn)
'''
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        ans = []
        for i in nums:
            ans.append(i*i)
        return sorted(ans)
'''
    
    
# O(n): counting sort , keeping track of multiple occrence , 2pass
'''
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        d = [0]*10001
        for i in nums:
            d[abs(i)]+=1
        
        ans = []
        for i in range(10001):
            while d[i]>0:
                ans.append(i*i)
                d[i]-=1
        return ans
'''
# O(n) 2 pointer, one pass


class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        i = 0
        j = n - 1
        ans = [0]*n
        
        while (n-1)>=0:
            if nums[i]*nums[i] > nums[j]*nums[j]:
                ans[n-1] = nums[i]*nums[i]
                n = n - 1
                i = i +1
            else:
                ans[n-1] = nums[j]*nums[j]
                n = n - 1
                j = j - 1
        return ans