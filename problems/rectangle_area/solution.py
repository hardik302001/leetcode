'''

Just compute the area of first and second rectangle minus area of the overlap. How to compute the overlap? It's two-dimensional, but we can break it down to two one-dimensional problems, one to find its width and one to find its height. How to find the overlap width? Well, the input rectangles occupy the intervals [A, C] and [E, G] on the x-axis. The overlap is the intersection of those intervals. How to find the intersection of two intervals? Just take the larger left end and the smaller right end, so in this case: [max(A, E), min(C, G)]. And the length of that interval is the width of the overlap, so min(C, G) - max(A, E). However, if there's no overlap, then max(A, E) is larger than min(C, G) and the "length" of that interval is negative. You could check whether max(A, E) is larger than min(C, G), but you can also just use the maximum of the potentially negative "length" and zero, as seen in the below code. 

'''


class Solution:
    
    def computeArea(self, A, B, C, D, E, F, G, H):
        first = (C - A) * (D - B)
        second = (G - E) * (H - F)
        overlap = max(min(C, G) - max(A, E), 0) * max(min(D, H) - max(B, F), 0)
        return first + second - overlap