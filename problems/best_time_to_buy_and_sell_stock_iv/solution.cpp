// (SAME AS BEST TIME TO BUY AND SEL STOCK 3)


class Solution {
public:
    int dp[1001][2][101];            //just chnged the constrants accordingly
    int maxProfit(int transac, vector<int>& prices) {
        int n = prices.size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<2;j++){
                for(int k = 0;k<transac;k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        int ans = recur(prices, 0 , 1,transac-1);  //I deliberately started from tarnsac -1, because when if I start from transac , I will assign value,then dp[i][buying][transac] will give segmentation fault, because its index is from 0 to transac-1, not 0 yo transac, so to avoid it I started from transac -1 ..
        return ans;
    }
    
    
    int recur(vector<int>&prices, int i, int buying, int transac){
        int buy, sell, cooldown;
        if(i>=prices.size()){
            return 0;
        }
        if (transac<0){
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