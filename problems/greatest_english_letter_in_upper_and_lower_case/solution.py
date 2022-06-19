class Solution:
    def greatestLetter(self, s: str) -> str:
        s = set(s)
        for c in 'abcdefghijklmnopqrstuvwxyz'[::-1] :
            if c in s and c.upper() in s :
                return c.upper()
        return ''