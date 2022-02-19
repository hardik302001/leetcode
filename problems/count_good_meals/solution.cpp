class Solution {
public:
    long long  countPairs(vector<int>& del) {
       unordered_map<long long, long long>mp;
        for(auto it: del){
            mp[it]++;
        }
        
        long long ans = 0;
        for(auto it: mp){
            for(int i = 0;i<22;i++){
                if ((1<<i)-it.first >= it.first and mp.count((1<<i)-it.first)){
                    if ((1<<i)==2*it.first){
                        ans = ans + (it.second*(it.second-1)/2)%1000000007;
                        ans = ans % 1000000007;
                    }
                    else{
                        ans = ans + (it.second*mp[(1<<i)-it.first])%1000000007;
                        ans = ans % 1000000007;
                    }
                }
            }
        }
        
        return ans;
    }
};