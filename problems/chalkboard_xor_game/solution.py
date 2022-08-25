# https://leetcode.com/problems/chalkboard-xor-game/discuss/190068/O(n)-simple-python3-with-explanation-beats-100

class Solution(object):
    def xorGame(self, nums):

        r_xor = 0
        for num in nums:
            r_xor = r_xor ^ num
        
        if r_xor == 0:
            # if xor of all elements is 0, then Alice wins
            return True
        
        # Alice wins if and only if there is an even number of numbers
        return len(nums) % 2 == 0