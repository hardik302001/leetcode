class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        vector<pair<int,int>>v;
        for(int i=0;i<d.size();i++){
            v.push_back({d[i],p[i]});
        }
        sort(v.begin(),v.end());
        int n=d.size();
        vector<int>dp(n+1);
        dp[0]=v[0].second;
        for(int i=1;i<n;i++){
            dp[i]=max(dp[i-1],v[i].second);
        }
        sort(d.begin(),d.end());
        int s=0;
        for(int i=0;i<w.size();i++){
           int in=upper_bound(d.begin(),d.end(),w[i])-d.begin();
           if(in!=0){
               in--;
               s+=dp[in];
           }
        }
        return s;
    }
};