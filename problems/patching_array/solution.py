'''Let's see a situation, for example the n is 10 and nums is empty, the optimal solution to "reach" 10 is 0 1 2 4 7 15, we can find the pattern that we start from stack = [0], the next number should be sum of stack plus 1 equal to 1, and put 1 into stack, it become [0, 1], then the next number should be 2, the stack should be [0, 1, 2]...
Then what about if we have a 3 in nums?

1. [0]
2. [0, 1]
3. [0, 1, 2]
4. [0, 1, 2, 4] # becase 4 is greater than 3 which we already have in nums, let's replace 4 with 3
4. [0, 1, 2, 3]
5. [0, 1, 2, 3, 7] # next step will reach target n=10!
6. [0, 1, 2, 3, 7, 14]
If current nums is >= nums[i], use nums[i] replace current number and add it into SUM until SUM is >= n.
'''



#Everytime we are checking (s+1) for next itertation
class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        ret = i = s = 0 # ret: return value, s: SUM
        while True:
            if s >= n:
                return ret
            if i < len(nums) and (s + 1) >= nums[i]:
                s += nums[i]
                i += 1
            else:
                s += s + 1
                ret += 1