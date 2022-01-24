class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        p = text.split()
        ans = []
        n = len(p)
        for i in range(n-1):
            if p[i]==first and p[i+1]==second:
                if i+2<n:
                    ans.append(p[i+2])
        return ans