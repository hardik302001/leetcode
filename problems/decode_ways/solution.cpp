typedef long long ll;

class Solution {
public:
    string s;
    int dp[101];

    int numDecodings(string &S) {
        s = S;
        memset(dp, -1, sizeof dp);
        ll ans = help(0);
        return ans;
    }
	
	ll help(int pos){
        //If we reach the end means it is valid decoding
        if(pos >= s.size()){
            return 1;
        }
        
        //result is available to us in cache
        if(dp[pos] != -1) return dp[pos];
        
        //No decoding is possible if current character = 0
        if(s[pos] == '0'){
            return dp[pos] = 0;
        }
        
        //decode normally
        ll ans = help(pos+1);
        
        //10 to 19 case
        if(s[pos] == '1' && pos +1 < s.size()){
            ans += help(pos+2);
        }
        //20 to 26 case
        else if(s[pos] == '2' && pos +1 < s.size() && s[pos+1] <= '6'){
            ans += help(pos+2);
        }
        
        return  dp[pos] = ans;
    }
};