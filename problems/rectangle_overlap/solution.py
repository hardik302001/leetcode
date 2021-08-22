class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        A = rec1[0]
        B = rec1[1]
        C = rec1[2]
        D = rec1[3]
        E = rec2[0]
        F = rec2[1]
        G = rec2[2]
        H = rec2[3]
        overlap = max(min(C, G) - max(A, E), 0) * max(min(D, H) - max(B, F), 0)   #area of overlap rectangle
        if overlap:
            return True
        else:
            return False