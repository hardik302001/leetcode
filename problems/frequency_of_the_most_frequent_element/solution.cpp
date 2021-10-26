//SLIDING WINDOW


class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
       long long int left=0,n=nums.size(),dist=0,best=1;
        sort(nums.begin(),nums.end());
       
        for(int right = 1;right<n;right++){
            
            dist+=(right-left)*(nums[right]-nums[right-1]);   //bring all segment of prev elements[left, right-1] equal to cur element i.e. nums[right] 
            
            while(dist>k){
                dist-=(nums[right]-nums[left]);
                left++;
            }
        
            best=max(best,right-left+1);
        }
        
        return best;
    }
};
