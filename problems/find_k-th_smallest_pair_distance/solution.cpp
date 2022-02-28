// binary search on answer + sliding window

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int r = nums[n-1]-nums[0];
        while(l<r){
            int m = l + (r-l)/2;
            if(check(nums, m , k)){
                r = m;
            }else{
                l = m + 1;
            }
        }
        
        return l;
    }
    // Is there k or more pairs with distance <= mid?
    bool check(vector<int>& nums, int m, int k){
        
        // sliding window for calculating pairs
        int c = 0;
        int n = nums.size();
        int left = 0;
        for (int right = 1;right<n;right++){
            while(nums[right]-nums[left] > m){
                left++;
            }
            c = c + (right - left);
        }
        
        return c>=k;
        
    }
};