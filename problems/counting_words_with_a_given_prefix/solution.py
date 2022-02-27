class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        c = 0
        p = len(pref)
        for i in words:
            if i[:p]==pref:
                c+=1
        return c