//very similar to best time to buy and sell stock with cooldown 
//coding idea from codencode..
//logic idea is same as best time to buy and sell stock with cooldown 
//just make new variable for transactions
//and update transaction only when you have sell the stock
//update code for cooldown, we dont need cooldown, so directly i+1 all time...

class Solution {
public:
    int dp[100001][2][3];
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<2;j++){
                for(int k = 0;k<3;k++){        
                    dp[i][j][k] = -1;
                }
            }
        }
        int ans = recur(prices, 0 , 1, 2);    // 3 choice possible , 0 transac , 1 transac , 2 transac
        return ans;
    }
    
    
    int recur(vector<int>&prices, int i, int buying, int transac){
        int buy, sell, wait;
        if(i>=prices.size()){
            return 0;
        }
        if (transac==0){ 
            return 0;       // bcz we cant do no more transactions , so we will have profit as 0
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
            
            // one transac completed
            wait = recur(prices, i+1, buying,transac); 
            dp[i][buying][transac] = max(wait, sell);
        }
            
        return dp[i][buying][transac];
    }
    
};