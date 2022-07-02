class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int mi = INT_MAX;
        int ma = INT_MIN;
        vector<int>mini;
        vector<int>maxi;
        int ans = -1;
        for(int i = 0;i<n;i++){
            mi = min(mi , nums[i]);
            mini.push_back(mi);
        }
        for(int i = n-1;i>=0;i--){
            ma = max(ma , nums[i]);
            maxi.push_back(ma);
        }
        
        reverse(maxi.begin(), maxi.end());
        for(int i = 0;i<n;i++){
            cout<<mini[i]<<" "<<maxi[i]<<endl;
        }
        
        for(int i = 0;i<n-1;i++){
            if(maxi[i+1]>mini[i]){
                ans = max(ans, maxi[i+1]-mini[i]);
            }
        }
        return ans;
        
    }
};