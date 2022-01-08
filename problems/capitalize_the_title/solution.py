class Solution:
    def capitalizeTitle(self, title: str) -> str:
        l =  list(title.split())
        ans = ""
        for i in l:
            if len(i)==1 or len(i)==2:
                ans = ans + i.lower()
            else:
                ans = ans + i.title()
            ans = ans + " "
        return ans[:-1]