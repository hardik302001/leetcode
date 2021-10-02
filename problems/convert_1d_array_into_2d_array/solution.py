class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        l = len(original)
        if l==(m*n):
            ans = []
            c = 0
            p = []
            for i in original:
                
                p.append(i)
                c = c + 1
                if c==n:
                    c = 0
                    ans.append(p)
                    p = []
        else:
            ans = []
        return ans