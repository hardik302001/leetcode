class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==1){ return; }
        int idx = n-2;
        int prev = nums[n-1];
        while(idx>=0 and nums[idx]>=prev){
            prev = nums[idx];
            idx--;
        }
        
        
        if(idx==-1){
            vector<int>ans = nums;
            sort(begin(nums), end(nums));
            return;
        }
        
        
        int swa = idx+1;
        for(int i = idx+1;i<n;i++){
            if(nums[i]>nums[idx]){
                swa = i;
            }else{
                break;
            }
        }
        
        swap(nums[idx], nums[swa]);
        int l = idx+1;
        int r = n-1;
        // cout<<l<<" "<<r<<endl;
        while(l<r){
            swap(nums[l++], nums[r--]);
        }
        return ;
        
    }
};