class Solution:
    def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
        sqlen = set()
        
        def cal_dist(a, b):
            return (a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2
        
        def issame(a, b):
            return a[0] == b[0] and a[1] == b[1]
        
        if issame(p1, p2) or issame(p2, p3) or issame(p3, p4) or issame(p1, p4) or issame(p1, p3) or issame(p2, p4):
                return 0
            
        sqlen.add(cal_dist(p1, p2))
        sqlen.add(cal_dist(p2, p3))
        sqlen.add(cal_dist(p3, p4))
        sqlen.add(cal_dist(p1, p4))
        sqlen.add(cal_dist(p1, p3))
        sqlen.add(cal_dist(p2, p4))
        
        return len(sqlen) == 2