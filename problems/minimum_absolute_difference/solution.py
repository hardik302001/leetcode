class Solution:
    def minimumAbsDifference(self, a: List[int]) -> List[List[int]]:
        a.sort()
        ans, diff = [], float('inf')
        for i in range(1, len(a)):
            if diff >= a[i] - a[i - 1]:
                if diff > a[i] - a[i - 1]:
                    ans = []
                    diff = a[i] - a[i - 1]
                ans.append([a[i - 1], a[i]])
        return ans
