/*Given an array, we need to find the peak element.
As, the subportions of the array are increasing/decreasing ( only then we would be able to find peak ), there are subportions of array which are sorted, so we could use binary search to get this problem done. But exactly how ?

This is an interesting part.

For a mid element, there could be three possible cases :
image

Case 1 : mid lies on the right of our result peak ( Observation : Our peak element search space is leftside )
Case 2 : mid is equal to the peak element ( Observation : mid element is greater than its neighbors )
Case 3 : mid lies on the left. ( Observation : Our peak element search space is rightside )

so, the code becomes

int start = 0;
int end = n-1;

while(start <= end) {
	int mid = start + (end - start)/2;
	if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;   // if mid == peak ( case 2 )
	else if(nums[mid] < nums[mid-1]) end = mid - 1; // downward slope and search space left side ( case 1)
	else if(nums[mid] < nums[mid+1]) start = mid + 1; // upward slope and search space right side ( case 3 )
}
Some base cases :

The array could be strictly increasing or strictly decreasing and as we have to return any of the possible peaks, so we could add a condition to check whether the 1st element/last element could be the peak ). This point is also supported by the fact that, we are looking for mid-1/ mid+1 ( and these indices are compremised for 0th index / n-1 th index respectively.

So, our complete code becomes

*/
		
            

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // support variables
        int l = 0, mid, r = nums.size() - 1;
        // edge cases:
        // mono-element input or first element as a peak
        if (!r || nums[0] > nums[1]) return 0;
        // last element as a peak
        if (nums[r - 1] < nums[r]) return r;
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
