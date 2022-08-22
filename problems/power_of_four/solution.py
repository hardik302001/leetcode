class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        return num > 0 and bin(num).count('1') == 1 and len(bin(num)) % 2 == 1

