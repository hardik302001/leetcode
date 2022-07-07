/*


COURTESY : CODEBIX
ALSO SEE:   https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii


*/


class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1;
        while (lo < hi) {
            int mid = lo + (hi-lo)/2;
            if (nums[mid] <= nums[hi]) {    //always we are comparing with end!   , you can do it wrt first position also, see SOLUTION for more info
                hi = mid;  //check in left half
            } else {
                lo = mid+1; //check in right half
            }
        }
        return nums[lo];
    } 
    
};






