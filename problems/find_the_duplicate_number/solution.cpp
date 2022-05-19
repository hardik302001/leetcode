/*

Time Complexity: O(n)
Space Complexity: O(1)

*/

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