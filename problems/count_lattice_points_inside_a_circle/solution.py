class Solution:
    def countLatticePoints(self, circles: List[List[int]]) -> int:
        seen = set()
        for x,y,r in circles:
            for x0 in range(x-r, x+r+1):
                for y0 in range(y-r,y+r+1):
                    if (x-x0) ** 2+ (y-y0)**2 <= r*r:
                        seen.add((x0, y0))
        return len(seen)
