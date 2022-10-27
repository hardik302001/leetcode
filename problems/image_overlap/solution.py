class Solution:
    def largestOverlap(self, A: List[List[int]], B: List[List[int]]) -> int:
        # get all ocuurence of 1 in both images
        A= [(i,j) for i, row in enumerate(A) for j , item in enumerate(row) if item==1 ]
        B =[(i,j) for i , row in enumerate(B) for j , item in enumerate(row) if item==1 ]
        
        # now we overlap every pair of 1 value coord from both image..
        # so if Ai overlap with Bi, then all coords with corrosponding distance differnce between x and y equal to Ai - Bi will contribute to that overlap situation
        
        # we count all such cases in Counter, nad return maximum of it
        
        # we are considering distance difference (ax-bx, ay-by) bcz if in some overlap situation 
        # ax , bx and ay , by overlap, then all other coordinates will also have same distance difference
        
        
        count=collections.Counter((ax-bx,ay-by) for ax, ay in A for bx,by in B)
    
        # what if count if empty , so we append 0 to it
        return max(list(count.values()) + [0])