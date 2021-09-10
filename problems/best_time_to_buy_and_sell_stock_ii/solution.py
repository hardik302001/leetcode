class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        i = 0
        profit = 0
        n = len(prices)-1
        
        while i<n:
            while i<n and prices[i+1]<=prices[i]:
                i = i +1
            buy = prices[i]
            
            while i<n and prices[i+1]>prices[i]:
                i = i +1
            sell = prices[i]
            
            profit = profit + sell - buy
        return profit
        
        
        
#         max_profit = 0
#         for i in range(len(prices) - 1):
#             max_profit += max(prices[i+1] - prices[i], 0)
#         return max_profit