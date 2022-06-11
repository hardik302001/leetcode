class Solution:
    def strongPasswordCheckerII(self, p: str) -> bool:
        sp = "!@#$%^&*()-+"
        alp = "qwertyuiopasdfghjklzxcbvnm"
        ALP = "QWERTYUIOPLKJHGFDSAZXCVBNM"
        dig = "1234567890"
        return len(p)>=8 and any(i in sp for i in p) and any(i in alp for i in p) and any(i in ALP for i in p) and any(i in dig for i in p) and (not any(p[i]==p[i+1] for i in range(len(p)-1)))