class Solution:
    def numberOfDays(self, Y: int, M: int) -> int:
        if M in {1,3,5,7,8,10,12}: return 31
        elif M != 2: return 30
        else: return 28 + (Y % 4 == 0 and Y % 100 != 0 or Y % 400 == 0)