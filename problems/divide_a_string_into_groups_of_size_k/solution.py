class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        
        if len(s)%k!=0:
            s = s + fill*(k - len(s)%k)
        # print(s)
        ans = []
        n = len(s)
        p = ""
        for i in range(n):
            p = p + s[i]
            if (i+1)%k==0:
                ans.append(p)
                p = ""

        return ans