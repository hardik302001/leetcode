class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        int n = gifts.size();
        for(auto x: gifts){
            pq.push(x);
        }
        
        while(k--){
            auto topa = pq.top();
            pq.pop();
            pq.push(int(sqrt(topa)));
        }
        
        long long res = 0;
        while(pq.size()){
            res += pq.top();
            pq.pop();
        }
        
        return res;
    }
};