// this problem is unique
// also see: very importnat ques : https://www.youtube.com/watch?v=MM7fXopgyjw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=53

// very important to conisder states


// our subproblem will be to burst first , calculate and partition fr next stage
// suppose 5 elements, i partition at 3rd position, next stae we have (0,2) and (4,5) and cur res = arr[2]*arr[3]*arr[4]
// next for (0,2), suppose i partition at 2, so for result calculation i will need arr[4], so substates are not independent...

// thus our subproblem is wrong... we need other way to express our subproblem bcz states should be independent. 



// we will go other way, we say we will burst arr(x) at end, so that we can consider its contribution 


class Solution {
public:
    
    int dp[301][301];
    int recur(int x, int y, vector<int>&arr){
        if(x>y) return 0;
        
        if(dp[x][y]!=-1) return dp[x][y];
        int mi = 0;
        int res = (x-1<0 ?1:arr[x-1])*(y+1>=arr.size()?1:arr[y+1]);  // very important
        for(int i = x;i<=y;i++){
            int ans = res*arr[i] + recur(x, i-1 , arr) + recur(i+1, y , arr);
            mi = max(mi , ans);
        }
        return dp[x][y] = mi;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        memset(dp , -1 , sizeof dp);
        return recur(0 , n-1, nums);   
    }
};