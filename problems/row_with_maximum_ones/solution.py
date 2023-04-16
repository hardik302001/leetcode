class Solution:
    def rowAndMaximumOnes(self, mat: List[List[int]]) -> List[int]:
        rowid = 0
        row_count = mat[0].count(1)
        n = len(mat)
        for i in range(1, n):
            cur = mat[i].count(1)
            if cur>row_count:
                rowid = i
                row_count = cur
        return [rowid , row_count]