# tc:      O(n2)
# see if for refernce=> O(n3) solutionis good, traverse from back..


class Solution:
    def countQuadruplets(self, nums: List[int]) -> int:
		# We are looking for a < b < c < d that satisfies equation nums[a] + nums[b] == nums[d] - nums[c]
        n = len(nums)
        res = 0
        d = {}
        d[nums[0] + nums[1]] = 1 # intial count for i == 2 
        for i in range(2, n - 1):
            for j in range(i + 1, n):
                # i < j, i => c and j => d
                if nums[j] - nums[i] in d:
                    res += d[nums[j] - nums[i]] # look for counts of result of right hand side of the equation with nums[i]
            
            for j in range(i):
                # i > j, i => b and j => a
                if nums[i] + nums[j] in d:
                    d[nums[i] + nums[j]] += 1 # add new sums with nums[i] of left hand side to the dictionary
                else:
                    d[nums[i] + nums[j]] = 1
        return res