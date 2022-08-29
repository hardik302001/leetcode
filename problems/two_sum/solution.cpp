class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans; //Here we declare a new dynamic array
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j] == target) { // now we equate the sum of array elements to the target value
                    ans.push_back(i); // Here, we push the indices of elements to the araay
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans; //we are returning the resultant array
    }
};