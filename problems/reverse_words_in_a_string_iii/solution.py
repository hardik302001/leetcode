class Solution:
    def reverseWords(self, s: str) -> str:
        l = []
        for i in s.split():
            l.append(i[::-1])
        return ' '.join(l)