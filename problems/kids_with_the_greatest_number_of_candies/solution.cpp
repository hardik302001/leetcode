class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
        vector<bool> ans;
        int n = candies.size();
        int ma  = 0;
        for(int i = 0;i<n;i++){
            ma = max(ma , candies[i]);
        }

        for(int i =0;i<n;i++){
            if(candies[i]+extra>=ma) ans.push_back(true);
            else                     ans.push_back(false);
        }
        return ans;
    }
};