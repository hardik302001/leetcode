// best time to buy and sell stock with cooldown

// easy dp
// sell after buy only , or wait
// start from buying state


class Solution {
public:
    int dp[100001][2];
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        memset(dp , -1 , sizeof dp);
        int ans = recur(fee , prices, 0 , 1);   
        return ans;
    }
    
    
    int recur(int fee , vector<int>&prices, int i, int buying){
        int buy, sell, wait;
        if(i>=prices.size()){
            return 0;
        }
        
        if (dp[i][buying]!=-1){
            return dp[i][buying];
        }
        int profit; 
        if (buying){           //if in buying state
            buy = recur(fee , prices, i+1, buying^1) - prices[i];   //if buy , then relative profit would be curr profit + (-price[i]) 
            wait = recur(fee , prices, i+1, buying); 
            profit = max(wait, buy);  //either you will buy or cooldown, 
        }
        else{
            sell = recur(fee , prices, i+1, buying^1) + prices[i] - fee; //if sell , then relative profit would be curr profit + (+price[i]) , also reduce the transac fee from profit
            
            // one transac completed
            wait = recur(fee , prices, i+1, buying); 
            profit = max(wait, sell);
        }
            
        return dp[i][buying] = profit;
    }
    
};