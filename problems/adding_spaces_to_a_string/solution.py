class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        ans = ""
        p = 0
        for i in range(len(s)):
            if(p<len(spaces) and i==spaces[p]):
                ans = ans + " "
                p = p +1
            ans = ans + s[i]
        return ans