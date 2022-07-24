class Solution:
    def repeatedCharacter(self, s: str) -> str:
        ss = set()
        for i in s:
            if i in ss:
                return i
            ss.add(i)
        