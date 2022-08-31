// also see: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/submissions/
// also see: https://www.interviewbit.com/problems/repeat-and-missing-number-array/
// also see: https://leetcode.com/problems/first-missing-positive/



/*

First of all, where does the cycle come from? Let's use the function f(x) = nums[x] to construct the sequence: x, nums[x], nums[nums[x]], nums[nums[nums[x]]], ....

Each new element in the sequence is an element in nums at the index of the previous element.

If one starts from x = nums[0], such a sequence will produce a linked list with a cycle.

The cycle appears because nums contains duplicates. The duplicate node is a cycle

The cycle appears because nums contains duplicates. The duplicate node is a cycle entrance
So we need to find entry point of cycle.

*/




// idea :  https://leetcode.com/problems/linked-list-cycle-ii/
// also see solution section! 



// Time Complexity: O(n)
// Space Complexity: O(1)



class Solution{
public:
    int findDuplicate(vector<int> &nums){

        int slow = nums[0];
        int entry = nums[0];
        int fast = nums[0];
        while (true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow==fast){
                while (slow != entry){
                    entry = nums[entry];
                    slow = nums[slow];
                } 
                return entry;
            }
        }
        
        return -1;
    }
};



// https://leetcode.com/problems/linked-list-cycle-ii/
// also see solution section! 

// https://leetcode.com/problems/find-the-duplicate-number/discuss/72846/My-easy-understood-solution-with-O(n)-time-and-O(1)-space-without-modifying-the-array.-With-clear-explanation.