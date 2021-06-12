class Solution:
    def sortSentence(self, s: str) -> str:
        s = s.split(" ")
        l = []
        for i in s:
            p = i[::-1]
            l.append(p)
        l.sort()
        # print(l)
        ans = ""
        for i in l:
            pp = i[::-1]
            ans = ans + pp[:-1]
            ans = ans + " "
        return ans[:-1]
    