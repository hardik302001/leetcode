class Solution:
    def checkString(self, s: str) -> bool:
        p = s.rfind('a')
        q = s.find('b')
        if p==-1:
            return 1
        if q==-1:
            return 1
        return p<q