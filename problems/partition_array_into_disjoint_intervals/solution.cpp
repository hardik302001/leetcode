
//Simple logic calculate max from left and min from right
//if(l[i]<=r[i+1])return i+1;


class Solution {
public:
    
     int partitionDisjoint(vector<int>& v) {
        int n=v.size(),l[n],r[n];
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            mx=max(v[i],mx);
            l[i]=mx;
        }
        int mn=INT_MAX;
        for(int i=n-1;i>=0;i--){
            mn=min(mn,v[i]);
            r[i]=mn;
        }
        for(int i=0;i<n-1;i++){
            if(l[i]<=r[i+1])return i+1;
        }
        return 0;
    }
    
};