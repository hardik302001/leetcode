class Solution {
public:
    int peakIndexInMountainArray(vector<int> nums) {
        int l = 0, mid, r = nums.size() - 1;
        // binary searching the input
        while (l < r) {
            mid = l + (r-l) / 2;
            if (nums[mid] > nums[mid + 1]) {
                if (nums[mid] > nums[mid - 1]) return mid;
                else r = mid;
            }
            else l = mid+1;
        }
        return -1;
    }
    
};