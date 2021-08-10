class Solution:
    def interpret(self, c: str) -> str:
        c = c.replace("()",'o')
        c = c.replace('(','')
        c = c.replace(')','')
        return c