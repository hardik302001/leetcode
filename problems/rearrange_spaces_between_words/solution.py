class Solution:
    def reorderSpaces(self, text: str) -> str:
        sp = text.count(" ")
        p = list(text.split())
        if len(p)==1:
            return p[0] + " "*sp
        eq = sp//(len(p)-1)

        ex = sp - eq*(len(p)-1)
        print(sp , eq, ex)
        ans = ''
        for i in p:
            ans = ans + i
            ans = ans + " "*eq
        ans = ans[:-eq] + " "*ex
        return ans