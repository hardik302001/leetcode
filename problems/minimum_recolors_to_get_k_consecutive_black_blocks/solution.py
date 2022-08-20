class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        ans = 100000
        n = len(blocks)
        l = 0
        c = 0
        for r in range(n):
            if blocks[r]=='B':
                c +=1
            
            
            if r-l+1==k:
                ans = min(ans, r-l+1-c)
                if blocks[l]=='B':
                    c-=1
                l+=1
        return ans
                    