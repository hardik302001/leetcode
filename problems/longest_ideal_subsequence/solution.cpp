// you cant do on the basis of indexing, 2d dp with 10power5. It wont work.

// ----------------------------------------------------------------------------

// we used ind of prev(ascii)
// prev = vertical bar ('|'), bcz it is next to 'z'
class Solution {
public:
    int dp(vector <vector<int>>&cache,string &s,int i,char prev,int &k){
        if(i==s.size()) return 0;
		
        if(prev=='*'){
            return max(1+dp(cache,s,i+1,s[i],k),dp(cache,s,i+1,prev,k));
        }
        
        int &ans=cache[i][prev-'a'];
        if(ans!=-1) return ans;
        
        if(abs(s[i]-prev)<=k){
            ans=max(1+dp(cache,s,i+1,s[i],k),dp(cache,s,i+1,prev,k));
        }
        else ans=dp(cache,s,i+1,prev,k);
        return ans;
    }
    
    int longestIdealString(string s, int k) {
        int n=s.size();
        vector <vector<int>> cache(n,vector <int>(26,-1));
        return dp(cache,s,0,'*',k);
    }
};