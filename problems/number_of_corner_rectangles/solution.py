class Solution:
    def countCornerRectangles(self, grid: List[List[int]]) -> int:
        
        rows, res = [], 0
        for row in grid:
            
            curr = set() #1
            
            for i,v in enumerate(row): #1
                if v: curr.add(i)
                    
            for prev in rows: #2
                overlap = len(prev & curr)
                res += (overlap - 1) * overlap // 2 #3
            
            rows.append(curr)
        
        return res