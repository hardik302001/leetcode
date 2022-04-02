class Solution:
    def triangularSum(self, l: List[int]) -> int:
        
        n = len(l)
        while n>1:
            for i in range(n-1):
                l[i] = (l[i]+ l[i+1])%10
            
            n-=1
        return l[0]
    
    # no extra space