// noice question
// sort + pq
// cf 1140 c


class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b, int k) {
        vector<vector<long long>>z;
        int n=a.size();
        for(int i=0;i<a.size();i++)
        {
            z.push_back({b[i],a[i]});
        }
        sort(z.begin(),z.end());
        long long sum=0;
        priority_queue<long long,vector<long long>,greater<long long>>q;
        for(int i=n-1;i>=(n-k);i--)
        {
            q.push(z[i][1]);
            sum+=z[i][1];
        }
        
        long long ans=sum*z[n-k][0];
        for(int i=n-k-1;i>=0;i--)
        {
            q.push(z[i][1]);
            sum+=z[i][1];
            sum-=q.top();
            q.pop();
            ans=max(ans,sum*z[i][0]);
        }
        return ans;
    }
};
