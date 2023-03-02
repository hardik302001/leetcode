class Solution:
    def isStrobogrammatic(self, num: str) -> bool:
        p = [2,3,4,5,7]
        same = [1, 0 ,8]
        dup = [6, 9]

        c = ''
        for i in num:
            if int(i) in p: return 0
            if int(i) in same: c+=i
            else: c+= '9' if i=='6' else '6'
        return c[::-1]==num