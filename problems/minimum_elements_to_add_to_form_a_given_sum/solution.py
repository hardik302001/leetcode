class Solution:
    def minElements(self, nums: List[int], limit: int, goal: int) -> int:
        s = sum(nums)
        need = goal - s
        return (abs(need) + limit-1)//limit