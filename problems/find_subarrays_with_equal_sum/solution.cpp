class Solution {
public:
    bool findSubarrays(vector<int>& nums) 
    {
        
        // second method
        for(int i=1;i<nums.size();i++)                                         // from 0 to n-1
        {
            int sum = nums[i-1]+nums[i];                                       // storing the current pair sum
            for(int j=i;j<nums.size()-1;j++)                                   // from i to n-1
            {
                if(nums[j]+nums[j+1]==sum) return true;                        // any point of time we get same pair of sum return true 
            }
        }
        return false;
    }  
};