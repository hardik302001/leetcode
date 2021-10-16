#see cpp soln

class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        s = ''.join(map(str, num))
        n = int(s)
        ans = n+k
        l = []
        for i in str(ans):
            l.append(i)
        return l