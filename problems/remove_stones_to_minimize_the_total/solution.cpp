class Solution {
public:
    int minStoneSum(vector<int>& a, int k) {
        priority_queue<int> q;
        for(int i:a) q.push(i);
        while(k--) {
            int cur=q.top();q.pop();
            q.push(cur-cur/2);
        }
        int ans=0;
        while(!q.empty()) {
            ans+=q.top();q.pop();
        }
        return ans;
    }
};