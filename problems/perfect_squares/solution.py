# TC : O(n*sqrt(n))
#DP SOLN


#At each step we are fixing dp[i] to its minimum possible number of perfect numbers that sum to i by checking all its possible square roots possible, and moving for next eleent...
class Solution:
    def numSquares(self, n: int) -> int:
        dp = [100000]*(n+1)
        dp[0] = 0
        
        for i in range(1,n+1):
            for j in range(1, int(i**(0.5))+1): #checking least number of perfect sqaure that sum to i, and updating it and updataion works until sqrt i only..
                dp[i] = min(dp[i], dp[i-j*j]+1)   #we are updating dp[i], not dp[j]
                #if dp[0], then it is a perfect square, we conisder it and do +1
                #if we do not find and interger sqaure root, then we can always use '1'..    
                    
                    
                    
                #print(i, " -> ",dp) , uncomment it to see dy run simulation
        return dp[n]