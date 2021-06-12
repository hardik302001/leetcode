class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        i = 0
        k = k % sum(chalk)

        while chalk[i]<=k:
            k = k - chalk[i]
            i = i +1
        return i
            
        