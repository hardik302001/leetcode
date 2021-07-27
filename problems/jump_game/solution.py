#courtesy TECHDOSE JUMP GAME SOLN

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if len(nums)==1:
            return True
        if nums[0]==0:
            return False
        n = len(nums)
        canReach = 0
        for i in range(n):
            if canReach<i:   #at that point we are stuck
                return False
            canReach=max(canReach, i+nums[i])
        return True
        