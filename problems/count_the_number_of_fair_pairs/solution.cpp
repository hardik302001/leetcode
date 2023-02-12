class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        long ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            int x=lower-nums[i],y=upper-nums[i]; // considering current element as part of fair pair
            auto it=lower_bound(nums.begin()+i+1,nums.end(),x);
            auto gt=upper_bound(nums.begin()+i+1,nums.end(),y);
            ans+=gt-it;
        }
        return ans;
    }
};