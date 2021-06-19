class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        f = 0
        for i in s:
            if f==0 and i=="0":
                f = 1
            if f==1 and i=="1":
                return False
        return True