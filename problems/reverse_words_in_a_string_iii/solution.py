class Solution:
    def reverseWords(self, s: str) -> str:
        l =list(s.split())
        ans = ""
        for i in l:
            ans = ans + i[::-1] + " "
        return (ans[:-1])