// dp
// dp[s] is length of longest chain ending at string s

class Solution {
public:
    
    int solve(string s, unordered_map< int, unordered_set < string > > &m, unordered_map<string, int>&dp){
        if(dp.count(s)){
           return dp[s];
        }
        
        int res = 1;
        if( m.count(s.size()-1) ==0){
            return dp[s] = res;
        }
        string temp = s;
        for(int i = 0;i<temp.size();i++){
            string newstr = temp.substr(0, i) + temp.substr(i+1);
            auto set = m[s.size()-1];
            auto it = set.find(newstr);
            if(it!=set.end()){
                res = max(res, 1 + solve(newstr, m, dp));
            }
        }
        
        return (dp[s] = res);
      
    }
    
    int longestStrChain(vector<string>& words) {
        unordered_map<int, unordered_set<string> >m;
        unordered_map<string, int> dp;
        for(auto w: words){
            m[w.size()].insert(w);
        }
        int n = words.size();
        int ans = -1;
        for(int i = 0;i<n;i++){
            int output = solve(words[i], m, dp);
            ans = max(ans,output );
        }
        
        // for(auto it: dp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        return ans;
    }
};