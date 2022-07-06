
# do read all solutions from SOLUTION SECTION!
# T.C. =  O(n)


class Solution:
    def longestConsecutive(self, nums):
        longest_streak = 0
        num_set = set(nums)

        for num in num_set:
            
            # if num is starting of the sequence then ( num - 1) should not exist in the set
            if num - 1 not in num_set:          # we are looking for starting of sequence...
                current_num = num
                current_streak = 1

                while current_num + 1 in num_set: # start looking for (num+1)'s and update num
                    current_num += 1
                    current_streak += 1

                longest_streak = max(longest_streak, current_streak)

        return longest_streak
    
    
# sort and find longest streak , nlogn


