import random
class Solution:
    def __init__(self, nums: List[int]):
        self.d = {}
        for i, v in enumerate(nums):
            if v not in self.d:
                self.d[v] = []
            self.d[v].append(i)

    def pick(self, target: int) -> int:
        return self.d[target][random.randint(0 , len(self.d[target])-1)]


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)