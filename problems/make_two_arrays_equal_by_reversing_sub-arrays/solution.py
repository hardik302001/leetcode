class Solution:
    def canBeEqual(self, target, A):
        return sorted(target) == sorted(A)