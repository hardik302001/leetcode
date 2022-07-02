// best time to buy and sell stock with cooldown

// easy dp
// sell after buy only , or wait
// start from buying state

// see py for one liner


class Solution {
public:
    int dp[100001][2];
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp , -1 , sizeof dp);
        int ans = recur(prices, 0 , 1);   
        return ans;
    }
    
    
    int recur(vector<int>&prices, int i, int buying){
        int buy, sell, wait;
        if(i>=prices.size()){
            return 0;
        }
        
        if (dp[i][buying]!=-1){
            return dp[i][buying];
        }
        int profit; 
        if (buying){           //if in buying state
            buy = recur(prices, i+1, buying^1) - prices[i];   //if buy , then relative profit would be curr profit + (-price[i]) 
            wait = recur(prices, i+1, buying); 
            profit = max(wait, buy);  //either you will buy or cooldown, 
        }
        else{
            sell = recur(prices, i+1, buying^1) + prices[i]; //if sell , then relative profit would be curr profit + (+price[i]) 
            
            // one transac completed
            wait = recur(prices, i+1, buying); 
            profit = max(wait, sell);
        }
            
        return dp[i][buying] = profit;
    }
    
};