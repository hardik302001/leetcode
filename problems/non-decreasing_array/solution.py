'''
# O(nlogn)

class Solution(object):
    def checkPossibility(self, nums):
        one, two = nums[:], nums[:]
        for i in range(len(nums) - 1):
            if nums[i] > nums[i + 1]:
                one[i] = nums[i + 1]
                two[i + 1] = nums[i]
                break
        return one == sorted(one) or two == sorted(two)
'''    

# O(n)
# very beautiful solution : https://leetcode.com/problems/non-decreasing-array/discuss/1190765/Non-decreasing-Array-or-JS-Python-Java-C%2B%2B-or-Simple-Solution-w-Visual-Explanation

class Solution:
    def checkPossibility(self, N: List[int]) -> bool:
        err = 0
        for i in range(1, len(N)):
            if N[i] < N[i-1]:
                if err or (i > 1 and i < len(N) - 1 and N[i-2] > N[i] and N[i+1] < N[i-1]):
                    return False
                err = 1
        return True