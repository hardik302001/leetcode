class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        o = []
        z = []
        ov = []
        zv = []
        
        for row in grid:
            oo = row.count(1)
            zz = row.count(0)
            o.append(oo)
            z.append(zz)
        rez = [[grid[j][i] for j in range(len(grid))] for i in range(len(grid[0]))]
        for row in rez:
            oo = row.count(1)
            zz = row.count(0)
            ov.append(oo)
            zv.append(zz)

        
        ans = []
        for i in range(len(grid)):
            t = []
            for j in range(len(grid[0])):
                # onesRowi + onesColj - zerosRowi - zerosColj
                x = o[i] + ov[j] - z[i] - zv[j]
                t.append(x)
            ans.append(t)
        
        return ans