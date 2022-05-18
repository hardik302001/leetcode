//NEETCODE YT SOLN
//we know profit = price[y] - price[x] , directly
 
//but how this comes directly
//when buy profit =  (-price[alpha])   , relative minus of price[alpha]
//when sell profit =  (+price[beta])   , relative plus of price[beta]

//so total profit  =  (price[beta] - price[alpha])         //we want this, directly...
//but we will use above 2 steps, to get it indirectly

class Solution {
public:
    //map<pair<int, int>,int > dp;          //unordered_map not working..giving compiler error, so i used map, but it is slow
                                          //better use 2d array with size [n][2]  , 2 for 2 choices, buying is true or false
    
    
    int dp[100001][2]; //global varible
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<2;j++){
                dp[i][j] = -1;
            }
        }
        
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
        
        int ans = 0;
        if (buying){           //if in buying state
            buy = recur(prices, i+1, buying^1) - prices[i];   //if buy , then relative profit would be curr profit + (-price[i]) 
            wait = recur(prices, i+1, buying);   
            ans = max(wait, buy);  //either you will buy or wait, 
            
        }
        else{
            sell = recur(prices, i+2, buying^1) + prices[i]; //if sell , then relative profit would be curr profit + (+price[i]) 
            //i+2 for cooldown , mentioned in ques
            wait = recur(prices, i+1, buying);   
            ans = max(wait, sell);
        }
            
        return dp[i][buying] = ans;
    
    }
};