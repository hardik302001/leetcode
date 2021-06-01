class Solution:
    def numJewelsInStones(self,J: str, S: str) -> int:
        charToFreqS = {}  # Map character to its frequency in S.
        numJewels = 0  # Total number of jewels.
        
        for ch in S:
            if ch not in charToFreqS:
                charToFreqS[ch] = 1
            else:
                charToFreqS[ch] += 1
        
        for ch in J:
            if ch in charToFreqS:
                numJewels += charToFreqS[ch]
                
        return numJewels