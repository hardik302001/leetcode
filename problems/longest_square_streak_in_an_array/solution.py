class Solution:
    def longestSquareStreak(self, nums: List[int]) -> int:
        nums.sort()
        ans = -1
        longest_streak = -1
        num_set = set(nums)

        for num in num_set:
            root = int(num**(0.5))
            # if num is starting of the sequence then (root(num)) should not exist in the set
            if root*root!=num or root not in num_set:          # we are looking for starting of sequence...
                current_num = num
                current_streak = 1

                while current_num**2 in num_set: # start looking for (num**2)'s and update num
                    current_num = current_num**2
                    current_streak += 1
                
                if(current_streak>=2):
                    longest_streak = max(longest_streak, current_streak)

        return longest_streak