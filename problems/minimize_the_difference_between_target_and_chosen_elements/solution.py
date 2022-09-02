class Solution:
    def minimizeTheDifference(self, mat, target):
        possible_min = sum([min(arr) for arr in mat])
        if possible_min >= target:
            return possible_min - target
        
        vals = {0}
        
        for row in mat:
            new_vals = set()
            for j in list(set(row)):
                for v in vals:
                    if v + j - target > target - possible_min:
                        continue
                    new_vals.add(v+j)
                    
            vals = new_vals
        
        return min(abs(target - v) for v in vals)
    
    
    
    
    
    
# =================================================================================

# brute force soln
'''

class Solution:
    def minimizeTheDifference(self, mat: List[List[int]], target: int) -> int:
        s = {0}
        for row in mat:
            new = set()
            s = { r + el for r in row for el in s}
        
        
        m = 1000000000
        for i in s:
            m = min(m, abs(i-target))
        return m
'''