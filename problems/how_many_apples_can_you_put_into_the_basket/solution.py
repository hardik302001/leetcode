class Solution:
    def maxNumberOfApples(self, arr: List[int]) -> int:
        arr.sort()
        apples = units = 0

        for weight in arr:
            units += weight
            if units > 5000:
                break

            apples += 1
        return apples