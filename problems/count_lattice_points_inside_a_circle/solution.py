class Solution:
    def countLatticePoints(self, circles: List[List[int]]) -> int:
        def inn(circle_x, circle_y, rad, x, y):
            if ((x - circle_x) * (x - circle_x) +
                (y - circle_y) * (y - circle_y) <= rad * rad):
                return True;
            else:
                return False;
            
            
        s = set()
        
        for circle in circles:
            
            r = circle[2]
            cx = circle[0]
            cy = circle[1]

            x1 = cx -r
            y1 = cy - r
            
            x2 = cx + r
            y2 = cy + r
            
            for i in range( x1 , x2+1):
                for j in range( y1 , y2 +1):
                    if((i-cx)**2 + (j-cy)**2<= r*r):
                        s.add((i, j))

        # print(s)
        return len(s)