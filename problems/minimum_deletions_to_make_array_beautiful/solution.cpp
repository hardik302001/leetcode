class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n =  nums.size();
        if(n==1){
            return 1;
        }
        int in = 0;
        int c= 0;
        for(int i = 1; i<n;i++){
            if(nums[in]!=nums[i]){
                i++;
                in = i;
            }else{
                c++;
            }
        }
        
        if(in<=nums.size()-1)c++;
        return c;
    }
};