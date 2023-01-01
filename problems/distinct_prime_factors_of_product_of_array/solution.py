class Solution:
    def distinctPrimeFactors(self, nums: List[int]) -> int:
        curr = set()
        for i in nums:
            j = 2
            while i > 1:
                while i % j == 0:
                    i //= j
                    curr.add(j)
                j += 1
        return len(curr)