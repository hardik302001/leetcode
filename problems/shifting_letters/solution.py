class Solution:
    def shiftingLetters(self, s: str, shifts: List[int]) -> str:
        n = len(shifts)
        su = sum(shifts)
        pre = 0
        for i in range(n):
            x = shifts[i] + pre
            shifts[i] = su - pre
            pre = x
        print(shifts) 
        ans = ''
        for i in range(n):
            calc = ( ord(s[i]) - 97  + shifts[i])%26 + 97
            ans =ans + chr(calc)
        return ans