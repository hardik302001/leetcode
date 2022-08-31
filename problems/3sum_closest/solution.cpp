/*
idk why , but python soln gives fucking TLE
*/



class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Sort vector of integers to perform modified binary search: Runtime O(nlogn)
        sort(nums.begin(), nums.end());
        
        // Construct variables for binary search
        int low, high, sum;
        
        // Minimum of 3 elements are required for sum, set intial closest sum: Runtime O(n)
        int closest = accumulate(nums.begin(), nums.begin() + 3, 0);
        
        // Iterate over elements to specify 1st out of 3 elements to sum
        for(int i = 0; i < nums.size() - 2; i++) {
            // Initialize high& low indices for binary search
            low = i + 1;
            high = nums.size() - 1;
            
            // Modified Binary Search: Runtime O(n)
            // [NOTE: value not guranteed to be in array, therefore runtime is O(n), not O(log n)]
            while(low < high) {
                // Calculate current sum
                sum = nums[i] + nums[low] + nums[high];
                
                // Update indices accordingly
                if(sum > target) {
                    high--;
                } else if(sum < target) {
                    low++;
                } else {
                    return target;
                }
                
                // Mimize the error to find the closest sum to target
                closest = abs(closest - target) < abs(sum - target) ? closest : sum;
            }
        }
        
        return closest;
    }
};