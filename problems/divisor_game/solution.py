# https://leetcode.com/problems/divisor-game/discuss/382233/Solution-in-Python-3-(With-Detailed-Proof)

class Solution:
    def divisorGame(self, n: int) -> bool:
        return n&1!=1