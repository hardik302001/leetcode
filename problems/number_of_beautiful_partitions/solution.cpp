// It is a simple DP solution,
// O(n*k)
//  here flag is used to check the length of any substring is greater or equal to minLength or not.    

class Solution {
    #define ll long long int
    const ll mod = 1e9 + 7;
    
    ll dp[1004][1004][2];
    
    // to check prime digit
    bool isPrime(char c) {
        return (c == '2' || c == '3' || c == '5' || c == '7');
    }
    
    ll solve(string &s, int i, int flag, int k, int minLength) {
        // if i is last index and k == 0 then the condition is fullfilled so return 1.
        int n = s.size();
        if(k==0 and i==n) return 1;
        if(k==0 or i>=n) return 0;
        // to chech dp array.
        ll &ans = dp[i][k][flag];
        if(ans != -1) return ans;
        
        
        ans = 0;
        
        // if the minlength condition is fullfilled then,
        if(flag) {
            // if current index if non prime then it can be last index of any valid substring, so here we can partion the string and flag become 0, because the condition of minlength (0 at this time) become false.
            if(!isPrime(s[i])) ans += solve(s, i + 1, 0, k - 1, minLength) % mod;  // now f = 0, so start new substring
            
            // we also have another option to proceed further without partioning.
            ans += solve(s, i + 1, flag, k, minLength) % mod;
        } 
        
        // if the flag is false means we are at first char of one substring.
        else {
            // if first char is non prime we will not proceed further.
            if(!isPrime(s[i])) return 0;
            
            // if it is prime we can start a new substring and we can go directly to the size of minlength by (i + m - 1) and flag become active.
            ans += solve(s, i + minLength - 1, 1, k, minLength) % mod;
        }
        
        // to prevent the overflow.
        ans %= mod;
        return ans;
    }
public:
    int beautifulPartitions(string s, int k, int minLength) {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 0, k, minLength);
    }
};




//----------------------------------------------------------------------------------------------------

// O(n*n*k)
// can be optimised further
/*
class Solution {
public:
     
    bool prime(char ch){
        return ch == '2' || ch == '3' || ch == '5' || ch == '7';
    }
    
    int mod = 1000000007;
    long dp[1001][1001];
    int recur(int i , int n , int k , int m, string &s){
        if(k==0 and i==n) return 1;
        if(k==0 or i>=n) return 0;

        if(dp[i][k]!=-1) return dp[i][k];
        if(!prime(s[i])) return dp[i][k] = 0;  // current is not prime      
        int c = 0;
        for(int x = i + m-1;x<n;x++){   // x is ending of current substring(that starts with i)
            if(!prime(s[x])){
                if(n-x-1<(k-1)*m) break;    // pruning
                else c = c%mod +  recur(x +1 , n, k-1 , m , s)%mod;
            }
        }
        
        return dp[i][k] = c%mod;
    }
    
    
    int beautifulPartitions(string s, int k, int m) {
        
        int n = s.size();
        if(prime(s.back()) or !prime(s[0])) return 0;
        memset(dp , -1 , sizeof dp);
        return recur(0 , n , k , m, s);
    }
};

*/