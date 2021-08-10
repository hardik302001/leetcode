class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        p = word
        up = p.upper()
        down = p.lower()
        tit = p.title()
        if word==up or word==down or word==tit:
            return True
        return False