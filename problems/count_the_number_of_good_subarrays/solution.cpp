class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        long long ans = 0;
        map<int, int>m;
        int c = 0;
        for(int r= 0;r<n;r++){
            m[nums[r]]++;
            c += (m[nums[r]]-1);  // add pairs with all other occurence excluding itself
            while (c>=k){
                int right = (n-r);  // we can extend subarray till end (beginning at index l)
                ans+=right;
                c -= (m[nums[l]]-1); // remove pairs
                m[nums[l]]-=1;
                l++;
            }
        }
        
        return ans;
    }
};