class Solution:
    def countPrefixes(self, words: List[str], s: str) -> int:
        c = 0
        for i in words:
            p = len(i)
            if s[:p]==i:
                c+=1
        return c