class Solution:
    def replaceDigits(self, s: str) -> str:
        al = 'abcdefghijklmnopqrstuvwxyz'
        n = len(s)
        res = ""
        for i in range(1,n,2):
            ch = s[i-1]
            sh = s[i]
            res = res + ch
            ind = al.find(ch)
            ind = (ind + 26 + int(sh))%26
            res = res + al[ind]
        if  n%2==1:
            res = res + s[-1]
        return res