//NEETCODE YT SOLN
//we know profit = price[y] - price[x] , directly


//but how this comes directly
//when buy profit =  (-price[alpha])   , relative minus of price[alpha]
//when sell profit =  (+price[beta])   , relative plus of price[beta]

//so total profit  =  (price[beta] - price[alpha])         //we want this, directly...
//but we will use above 2 steps, to get it indirectly

class Solution {
public:
    //map<pair<int, int>,int > dp;          //unordered_map not working..giving compiler error
                                          //better use 2d array with size [n][2]  , 2 for 2 choices, buying is true or false
    
    
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int> > dp(n, vector<int > (2,-1));
        return recur(prices, 0 , 1,dp);
    }
    
    
    int recur(vector<int>&prices, int i, int buying, vector<vector<int> > &dp){
        int buy, sell, cooldown;
        if(i>=prices.size()){
            return 0;
        }
        if (dp[i][buying]!=-1){
            return dp[i][buying];
        }
        
        cooldown = recur(prices, i+1, buying,dp);        
        if (buying){           //if in buying state
            buy = recur(prices, i+1, buying^1,dp) - prices[i];   //if buy , then relative profit would be curr profit + (-price[i]) 
            dp[i][buying] = max(cooldown, buy);  //either you will buy or cooldown, 
        }
        else{
            sell = recur(prices, i+2, buying^1,dp) + prices[i]; //if sell , then relative profit would be curr profit + (+price[i]) 
            dp[i][buying] = max(cooldown, sell);
        }
            
        return dp[i][buying];
    
    }
};