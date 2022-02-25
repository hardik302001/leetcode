class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:

        m = 0
        n = len(customers)
        p = [0]*(n+1)
        
        for i in range(n):
            if grumpy[i]==0:
                p[i+1] = p[i] + customers[i]
            else:
                p[i+1] = p[i]
      
        
        s = 0
        l = 0
        for r in range(n):
            s = s + customers[r]
            
            if (r-l+1)==minutes:
                tot =  p[l] + s + (p[n] - p[r+1])
                # print(p[l] , s , p[n] - p[r+1] , tot)
                m = max(m , tot)
                s = s - customers[l]
                l = l +1
            
            
        
        return m