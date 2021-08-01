'''
Idea:
If there are at least two projects with same number of milestones and there isn't a project with more milestones than that two, we can finish all milestones.
If not, we can only finish 2 * (sum(milestones) - max(milestones)) + 1 at most.

'''

class Solution:
    def numberOfWeeks(self, milestones: List[int]) -> int:
        s, m = sum(milestones), max(milestones)
        #(s-m) left elements from the max..
        #if m is more than these left elements, then we would only be able to cover 2*left + 1 eleemnts, 2*left bcz removing from left and m simulateneously, and +1 because we want maximum answer, so we will start from m and then go alternatively!
        
        #else m is less than equal to left then, 


        #         Example
        #         Let's say we have milestones like [5, 5, 3, 2].
        #         We can take turn working on those projects with the most milestones.
        #         So, [5, 5] will become [4, 4], then become [3, 3].
        #         Because we have another project with 3 milestones, so we can take turn working on [3, 3, 3].
        #         [3, 3, 3] after three rounds, will become [2, 2, 2].
        #         [2, 2, 2, 2] -> [1, 1, 1, 1] -> [0, 0, 0, 0] -> all the milestones are finished
        
        
        #it means we can cover all elements , so return sum
        if s - m >= m: 
            return s
        else:
            return 2 * (s - m) + 1  