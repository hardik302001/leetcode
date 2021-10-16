//very similar to best time to buy and sell stock with cooldown 
//coding idea from codencode..
//logic idea is same as best time to buy and sell stock with cooldown 
//just make new variable for transactions
//and update transaction only when you hav esell the stock
//update code for cooldown, we dont need cooldown, so directly i+1 all time...

class Solution {
public:
    int dp[100001][2][3];
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<2;j++){
                for(int k = 0;k<2;k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        int ans = recur(prices, 0 , 1,1);    //2 chioices 0, 1 (we started transac from 1, because we are using dp[i][buying][transac] , so if transac ==2, then that will resullt in SEGMENTFault , so I started with 2-1, in beginning only)
        return ans;
    }
    
    
    int recur(vector<int>&prices, int i, int buying, int transac){
        int buy, sell, cooldown;
        if(i>=prices.size()){
            return 0;
        }
        if (transac<0){ //if less than zero then break
            return 0;
        }
        if (dp[i][buying][transac]!=-1){
            return dp[i][buying][transac];
        }
             
        if (buying){           //if in buying state
            buy = recur(prices, i+1, buying^1,transac) - prices[i];   //if buy , then relative profit would be curr profit + (-price[i]) 
            cooldown = recur(prices, i+1, buying,transac); 
            dp[i][buying][transac] = max(cooldown, buy);  //either you will buy or cooldown, 
        }
        else{
            sell = recur(prices, i+1, buying^1,transac-1) + prices[i]; //if sell , then relative profit would be curr profit + (+price[i]) 
            cooldown = recur(prices, i+1, buying,transac); 
            dp[i][buying][transac] = max(cooldown, sell);
        }
            
        return dp[i][buying][transac];
    }
    
};