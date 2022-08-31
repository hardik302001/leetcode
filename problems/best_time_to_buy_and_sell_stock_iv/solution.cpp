// (SAME AS BEST TIME TO BUY AND SELL STOCK 3)
// there is some other soln also , with 2 state only , see striver video ...do that also later on..

// TC: O(nk)

class Solution {
public:
    int dp[1001][2][101];            //just chnged the constriants accordingly
    int maxProfit(int transac, vector<int>& prices) {
        int n = prices.size();
        memset(dp , -1, sizeof dp);
        int ans = recur(prices, 0 , 1,transac);  
        return ans;
    }
    
    
    int recur(vector<int>&prices, int i, int buying, int transac){
        int buy, sell, wait;
        if(i>=prices.size()){
            return 0;
        }
        if (transac==0){  // transactions are finished, no more transactions, so no more profit
            return 0;
        }
        if (dp[i][buying][transac]!=-1){
            return dp[i][buying][transac];
        }
             
        if (buying){           //if in buying state
            buy = recur(prices, i+1, buying^1,transac) - prices[i];   //if buy , then relative profit would be curr profit + (-price[i]) 
            wait = recur(prices, i+1, buying,transac); 
            dp[i][buying][transac] = max(wait, buy);  //either you will buy or cooldown, 
        }
        else{
            sell = recur(prices, i+1, buying^1,transac-1) + prices[i]; //if sell , then relative profit would be curr profit + (+price[i]) 
            wait = recur(prices, i+1, buying,transac); 
            dp[i][buying][transac] = max(wait, sell);
        }
            
        return dp[i][buying][transac];
    }
    
};