class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> runl(N), runr(N);
        
        runl[0] = 1;
        for (int i = 1; i < N; ++i){
            if (nums[i] <= nums[i-1]) runl[i] = runl[i-1]+1;
            else runl[i] = 1;
        }
        runr[N-1] = 1;
        for (int i = N-2; i >= 0; --i){
            if (nums[i] <= nums[i+1]) runr[i] = runr[i+1]+1;
            else runr[i] = 1;
        }
        
        vector<int> ans;
        for (int i = k; i < N-k; ++i){
            if (runl[i-1] >= k && runr[i+1] >= k) ans.push_back(i);
        }
        return ans;
    }
};