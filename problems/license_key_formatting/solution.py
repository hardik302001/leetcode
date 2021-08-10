class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        s = s.replace('-','')
        p =''
        for i in s:
            if i.islower():
                p = p + i.upper()
            else:
                p = p + i
        p = p[::-1]
        ans = ''
        for i in range(len(p)):
            if (i)%k==0:
                ans = ans + '-'
            ans = ans+ p[i]
        return ans[::-1][:-1]