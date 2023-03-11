import collections
class Solution:
    def longestLine(self, M: List[List[int]]) -> int:
        row = collections.defaultdict(int)
        col = collections.defaultdict(int)
        ad = collections.defaultdict(int)  # Ascending diagonal
        dd = collections.defaultdict(int)  # Descending diagonal
        mx = 0
        for i in range(len(M)):
            for j in range(len(M[0])):
                if not M[i][j]:
                    row[i] = col[j] = ad[j + i] = dd [j - i] = 0
                else:
                    row[i] += 1
                    col[j] += 1
                    ad[j + i] += 1
                    dd[j - i] += 1
                    mx = max(mx, row[i], col[j], ad[j+i], dd[j-i])
        return mx