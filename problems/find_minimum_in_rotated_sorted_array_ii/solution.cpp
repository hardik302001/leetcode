/*


COURTESY : CODEBIX
ALSO SEE:   https://leetcode.com/problems/find-minimum-in-rotated-sorted-array


*/


// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int lo = 0, hi = nums.size()-1;
//         while (lo < hi) {
//             int mid = lo + (hi-lo)/2;
//             if (nums[mid] < nums[hi]) {    //always we are comparing with end!   , you can do it wrt first position also
//                 hi = mid;  //check in left half
//             } else if(nums[mid] > nums[hi]) {
//                 lo = mid+1; //check in right half
//             }
//             else{  //if nums[mid]==nums[right]
//                  hi--;
//             }
//         }
//         cout<<lo;
//         return nums[lo];
//     }   
// };


// This solution is great, but I'd like to point out one thing: this solution guarantees to find the min value, but not necessarily the correct pivot index!
// e.g. [1,1,1,1,2,1,1], in this case, lo = 0 in the end, which is not the correct pivot index.
// With this "bug", it may cause error if we use this directly in LC81 - Search in Rotated Sorted Array II
// To fix this:
class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1;
        while (lo < hi) {
            int mid = lo + (hi-lo)/2;
            if (nums[mid] < nums[hi]) {    
                hi = mid;  //check in left half
            } else if(nums[mid] > nums[hi]) {
                lo = mid+1; //check in right half
            }
            else{  //if nums[mid]==nums[hi], bcz we dont know which way to go , left or right, so we cant ignore whole segment..
                 if (nums[hi - 1] > nums[hi]) {     //very impo step to get correct index of the minimum element as more than one minimum are possible
                                    //if we dont check this step here, then in next iteration we will get this situation again(bcz num[hi] == nums[mid]), the first condition of while loop and we wil make our hi = mid, but the answer lie in that part that we are cutting off!
                     //so we are checking this thing here only and making lo = hi and breaking...
                    lo = hi;
                    break;
                }
                hi--; 
            }
        }
        
        cout<<lo;           //gives correct index of minimum
        return nums[lo];
    }   
};


// see these tc for both codes
//[1,1,1,1,1,1,2,1,1]
//[3,3,3,3,3,1,1,2,3]