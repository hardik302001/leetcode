class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        p = []
        n = len(heights)

        for i in range(n):
            p.append([ heights[i], names[i]])
        p.sort(reverse = True)
        ans = []
        for i in p:
            ans.append(i[1])
        return ans