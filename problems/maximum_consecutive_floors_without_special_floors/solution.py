class Solution:
    def maxConsecutive(self, bottom: int, top: int, special: List[int]) -> int:
        special.sort()
        
        d = 0
     
        
        d = max(d , special[0]-bottom)
        d = max(d , top - special[-1])
        for i in range(1 ,len(special)):
            d = max(d , special[i]-special[i-1]-1)
        return d
        