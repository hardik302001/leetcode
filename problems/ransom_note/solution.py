class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        d = {}
        for i in magazine:
            if i in d:
                d[i] +=1
            else:
                d[i] = 1
        for i in ransomNote:
            if i in d:
                d[i] -=1
            else:
                return False
        for i in d:
            if d[i]<0:
                return False
        return True