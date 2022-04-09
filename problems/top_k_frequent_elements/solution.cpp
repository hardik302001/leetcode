


//similar to https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/


//  ------------- MAX HEAP ---------------------------  O( N log n)

// class Comp {
// public:
//         bool operator()(pair<int, int>& lhs, pair<int, int>& rhs){
//               if(lhs.first<rhs.first){    // true when a is smaller than b
//                     return true;
//                 }
//                 else if(rhs.first<lhs.first){
//                     return false;
//                 }
//                 else{
//                     if(lhs.second<rhs.second){
//                         return true;
//                     }
//                     else{
//                         return false;
//                     }
//                 }
//         }
// };



// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
        
//         unordered_map<int, int> cnt;
//         for (auto& w : nums)
//             ++cnt[w];
        
//         priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> Q;  // max heap
        
//         for (auto it : cnt)
//             Q.push({it.second, it.first});
        
//         vector<int> res;
//         while (k-- and !Q.empty()) {
//             res.push_back(Q.top().second);
//             Q.pop();
//         }
        
//         return res;
//     }
// };



// ------------------- MIN HEAP --------------------    O(n logk)

// class Comp {
// public:
//         bool operator()(pair<int, int>& lhs, pair<int, int>& rhs){
//               if(lhs.first>rhs.first){    // true when a is greater than b
//                     return true;
//                 }
//                 else if(rhs.first>lhs.first){
//                     return false;
//                 }
//                 else{
//                     if(lhs.second>rhs.second){
//                         return true;
//                     }
//                     else{
//                         return false;
//                     }
//                 }
//         }
// };



// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
        
//         unordered_map<int, int> cnt;
//         for (auto& w : nums)
//             ++cnt[w];
        
//         priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> Q;  // min heap
        
//         for (auto it : cnt){
//             Q.push({it.second, it.first});
//             if(Q.size()>k){  // keep only top k elements
//                 Q.pop();
//             }
//         }
        
//         vector<int> res;
//         while (!Q.empty()) {
//             res.push_back(Q.top().second);
//             Q.pop();
//         }
        
//         return res;
//     }
// };



// ------------------------- BUCKET SORT ----------------------------   O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        if (!nums.size()) return res;
        unordered_map<int, int> cnt;
        for (auto num : nums) cnt[num]++;
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto kv : cnt) {
            bucket[kv.second].push_back(kv.first);
        }

        for (int i = bucket.size() - 1; i >= 0; --i) {
            for (int j = 0; j < bucket[i].size(); ++j){
                res.push_back(bucket[i][j]);
                if (res.size() == k) return res;
            }
        }

        return res;
    }
};