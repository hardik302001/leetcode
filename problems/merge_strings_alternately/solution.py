class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        ans = ""
        word1 = word1[::-1]
        word2 = word2[::-1]
        while word1 or word2:
            if word1:
                ans = ans + word1[-1]
                word1 = word1[:-1]
            if word2:
                ans = ans + word2[-1]
                word2 = word2[:-1]
        return ans