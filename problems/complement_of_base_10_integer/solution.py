class Solution:
    def bitwiseComplement(self, n: int) -> int:
        if n==0:
            return 1
        
        ans = 0
        i = 1
        while i<=n:
            # print(i)
            top = i&n
            if top==0:
                ans = ans + i
            i = i<<1
        
        return ans