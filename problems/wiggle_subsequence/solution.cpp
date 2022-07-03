// https://leetcode.com/problems/wiggle-subsequence/discuss/2229495/C%2B%2B-O-(-N-)-oror-EXPLAINED-oror
// https://leetcode.com/problems/wiggle-subsequence/discuss/1115385/Short-and-Easy-w-Explanation-or-O(N)-time-O(1)-Space
// we want length , not number of valleys , so thats why we considered max at end!

/*
Solution - I (Dynamic Programming)

The problem asks us to find a sequence where differences of adjacent elements alternate between +ve & -ve. The problem can be restated as Find the number of max and min peaks in the given array.

We can iterate over the array and find these possibilities :

nums[i] > nums[i - 1]
nums[i] < nums[i - 1]
nums[i] == nums[i - 1]
We maintain two variables up and down both initialised to 1 (1st element will always be chosen). They denote maximum number of peaks till now with last peak being a max peak and min peak respectively.

If we come across condition 1, we have encountered a possible max peak. We update up as 1 + down (1 + maximum number of peak till last min peak). However, if the next element is again coming under condition 1, we know that last peak shouldn't have been considered. So, we again update up as 1 + down denoting that the current peak has been considered as max peak.

This process is repeated for down as well when we come across condition 2. We update down as 1 + up (1 + maximum number of peak till last max peak).

When condition 3 is encountered, we are sure that it is neither a max nor a min peak, so we just skip that iteration.
*/



class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = size(nums), len = 1, up = 1, down = 1;
        for(int i = 1; i < n; i++)
            if(nums[i] < nums[i - 1]) up = 1 + down;
            else if(nums[i] > nums[i - 1]) down = 1 + up;
        // array could start with min-peak or max-peak depending on which any of up & down could be our answer
        return max(up, down); 
    }
};


// Time Complexity : O(N), for traversing the array.
// Space Complexity : O(1), since only constant space is used.
