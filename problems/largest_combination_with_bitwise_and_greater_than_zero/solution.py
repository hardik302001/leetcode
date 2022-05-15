class Solution:
    def largestCombination(self, cand: List[int]) -> int:
        a = cand
        n = len(a)
        l = [0 for i in range(32)]
        for i in range(n):
            x = 31
            while(a[i] > 0):
                if (a[i] & 1 == 1):
                    l[x] += 1
                a[i] = a[i] >> 1
                x -= 1

        
        return (max(l))