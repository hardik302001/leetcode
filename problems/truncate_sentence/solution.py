class Solution:
    def truncateSentence(self, s: str, k: int) -> str:
        l = list(s.split())
        p = l[:k]
        ans = ""
        for i in p:
            ans = ans + i + " "
        return ans[:-1]