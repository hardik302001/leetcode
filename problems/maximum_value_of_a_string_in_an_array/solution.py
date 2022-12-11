class Solution:
    def maximumValue(self, strs: List[str]) -> int:
        ans = 0
        for i in strs:
            if i.isdigit():
                ans = max(ans , int(i))
            else:
                ans = max(ans , len(i))
        return ans