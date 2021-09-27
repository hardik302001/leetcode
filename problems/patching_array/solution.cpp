// first part of ques..
//https://youtu.be/SO1lFWyaSdE

// patching array is follow up for above ques..
// https://leetcode.com/problems/patching-array/discuss/78492/C++-8ms-greedy-solution-with-explanation


// we always look for maxNum+1 as our next target, if it is less than current element ,then we need to add an extra element , else we us ethe current element bto go as forward as we can.

class Solution {
public:
int minPatches(vector<int>& nums, int n) {
    int cnt=0,i=0;
    long long maxNum=0;
    while (maxNum<n){
       if (i<nums.size() && nums[i]<=maxNum+1){
            maxNum+=nums[i];i++;
       }
       else{
            maxNum+=maxNum+1;cnt++;
       }
   }
   return cnt;
}
};