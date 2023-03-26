/*
If you reach a point where the prefix sum is less than zero, it's always best to push the minimum element so far to the end.

Approach
I keep a min heap of all elements so far. when I reach a point where prefix sum is less than zero I pop from heap the minimum element and subtract it from prefix sum. At the end I have to return the number of times that I popped from heap, which is size of nums - size of heap.

*/


class Solution {
public:
    int makePrefSumNonNegative(vector<int>& nums) {
        priority_queue<int , vector<int> , greater<int>>pq;
        long long cur = 0;
        for(auto x: nums){
            cur+= x;
            pq.push(x);
            if(cur<0){
                int topa = pq.top();
                pq.pop();
                cur-=topa;
            }
        }
        return (int)nums.size() - (int)pq.size();
    }
};