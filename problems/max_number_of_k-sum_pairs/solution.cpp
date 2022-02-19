class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int ans = 0;
        for(auto i: nums){
            if (mp.count(k-i)>0 and mp[(k-i)]>0){
                ans = ans + 1;
                mp[(k-i)]--;
            }else{
                mp[i]++;
            }
        }
        
        return ans;
    }
};