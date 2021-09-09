


class Solution:
    def minFallingPathSum(self, arr: List[List[int]]) -> int:
        rl, cl = len(arr), len(arr[0])
        memo = [float('inf') for _ in range(cl)]
        
        #m1, m2 are the two smallest number in the given arr, and i1 is the index of the smallest number
        def find_two_smallest(a):
            m1, m2 = float('inf'), float('inf')
            for i, x in enumerate(a):
                if x <= m1:
                    m1, m2, i1 = x, m1, i
                elif x < m2:
                    m2 = x
            return [m1, m2, i1]
        
        d = find_two_smallest(arr[0])
        for i in range(1,rl):
            for j in range(cl):
                if d[2] == j:
                    memo[j] = d[1] + arr[i][j]
                else:
                    memo[j] = d[0] + arr[i][j]
            d = find_two_smallest(memo)
        return d[0]