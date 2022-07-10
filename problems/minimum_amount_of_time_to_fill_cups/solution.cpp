class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int>pq;
        for(auto x: amount){
            if(x>0){
                pq.push(x);
            }
        }
        
        int ans= 0;
        while(pq.size()>1){
            int t1 = pq.top();
            pq.pop();
            int t2 = pq.top();
            pq.pop();
            ans++;            // do it one by one
            if(t1-1>0){
                pq.push(t1-1);
            }
            if(t2-1>0){
                pq.push(t2-1);
            }
        }
        
        ans+= pq.size()?pq.top():0;
        return ans;
        
        
    }
};