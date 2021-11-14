class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int>q;
        int n = tickets.size();
        for(auto i: tickets){
            q.push(i);
        }
        
        int ans= 0;
        
        int p = tickets[k];
        p--;
        
        for(int i = 0;i<=k;i++){
            int x = q.front();
            x--;
            q.pop();
            q.push(x);
            ans++;
        }
        
        for(int i = 0;i<n;i++){
            int x = q.front();
            int m = min(p,x);
            ans = ans +m;
            q.pop();
        }
        
        
        return ans;
        
        
    }
};