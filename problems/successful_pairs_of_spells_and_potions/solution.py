import bisect
class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        n = len(potions)
        ans = []
        for i in spells:
            need = (success+i-1)//i
            x = bisect.bisect_left(potions , need)
            c= (n-x)
            ans.append(c)
        return ans