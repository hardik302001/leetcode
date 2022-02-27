//SLIDING WINDOW
// https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1179374/Python-3-Sliding-Window-Explanation-with-Code

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
       long long int left=0,n=nums.size(),dist=0,best=1;
        sort(nums.begin(),nums.end());
       
        for(int right = 1;right<n;right++){
            
            dist+=(right-left)*(nums[right]-nums[right-1]);   //bring all segment of prev elements[left, right-1] equal to cur element i.e. nums[right] 
            
            while(dist>k){  // we want such dist , that we can change to current lement, so we remove the farthest elements..bcz they will ofc take large no. of moves...so we do left++;
                dist-=(nums[right]-nums[left]);  //remove contrib of current lement, that we have to remove i.e. nums[left]
                left++;
            }
        
            best=max(best,right-left+1);
        }
        
        return best;
    }
};
