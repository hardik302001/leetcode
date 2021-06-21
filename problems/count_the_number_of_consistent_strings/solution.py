class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        c = 0
        for i in words:
            f = 1
            s = set(i)
            for j in s:
                if j not in allowed:
                    f = 0
                    break
            if f:
                c = c+1
        return c