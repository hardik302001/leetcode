//for better method see previous code
//Method 2: Using priority queue of size k  (max heap)
// https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        return pq.top();
    }
};


//Time: In worst case, O(nlogk).

