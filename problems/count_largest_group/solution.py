class Solution:
    def countLargestGroup(self, n: int) -> int:
        
        d = {}
        for i in range(1, n + 1):
            t = sum(map(int, list(str(i))))
            if t not in d:
                d[t] = 1            
            else:
                d[t] += 1
            
        m = max(d.values())
        
        return sum(1 for i in d.values() if i >= m)