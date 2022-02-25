class Solution:
    def sumZero(self, n: int) -> List[int]:
        if n&1:
            ans = [x for x in range(-1*(n//2) , (n//2)+1)]
        else:
            ans = [x for x in range(-1*(n//2) , 0)] + [x for x in range( 1, (n//2)+1)]
        return ans