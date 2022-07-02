class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int cur = 0;
        
        
        for(auto x: nums){
            cur+=x;
            ans = max(ans , cur);
            
            
            if(cur<0){
                cur = 0;
            }
        }
            
        
        return ans;
            
    }        
    
};