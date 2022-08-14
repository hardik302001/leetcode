class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long int>s[n];
        for(int i = 0;i<n;i++){
            s[edges[i]].push_back(i);
        }
        int i = 0;
        int ind = -1;
        long long int ma = 0;
        for(auto v: s){
            long long int su = accumulate(v.begin(), v.end(), 0LL);
            
            if(su>ma){
                ma = su;
                ind = i;
            }
         
            i++;
        }
        return ind;
    }
};