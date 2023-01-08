class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto x: nums){
            pq.push(x);
        }
        
        long long ans = 0;
        while(k--){
            auto topa = pq.top();pq.pop();
            ans+=topa;
            pq.push((topa+3-1)/3);
        }
        return ans;
    }
};