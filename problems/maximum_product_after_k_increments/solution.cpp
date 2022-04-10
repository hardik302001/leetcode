#define ll long long

class Solution {
public:
    ll maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int> , greater<int>>pq(nums.begin() , nums.end());
        ll m = 1000000007;
        while(k--){
            int topa = pq.top();
            pq.pop();
            pq.push(topa+1);
        }
        
        
        ll ans = 1;
        while(pq.size()){
            ans*=pq.top();
            ans%=m;
            pq.pop();
        }
        
        return ans;
    }
};