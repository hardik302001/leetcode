/*

(0)     // case 1
(1-9)    // case 2
(*)      // case 3

(1)(0-9)   // case 4
(2)(0 - 6)   // case 5
(1)*   // case 6
(2)*   // case 7

*(0-9)    if star is 1  // case 8
*(0-6)    if star is 2  // case 9

**    [1][1-9] +  [2][1-6] => 15 cases  // case 10
       case 8      case 9

*/

typedef long long ll;

class Solution {
public:
    ll m = 1e9+7;
    string s;
    
    ll dp[100001];
    
    int numDecodings(string &S) {
        s = S;
        for(int i = 0 ; i <= s.size(); i++){
            dp[i] = -1;
        }
        ll ans = help(0);
        return ans;
    }
    
    ll help(int pos){
        //we have reached the end. It is a possible decoding.
        if(pos >= s.size()){
            return 1;
        }
        
        //check cache
        if(dp[pos] != -1) return dp[pos];
        
        //no decoding is possible if current char is 0
        if(s[pos] == '0'){                               // case 1
            return dp[pos] = 0;
        }
        
        //decode normally considering the current char to be anything 1-9 or *
        ll ans = help(pos+1);   // case 2
        if(s[pos] == '*'){
            //if current char is * it can take values from 1-9 therefore multiply by 9
            ans *= 9;       // case 3
            
            //consider current * as 1
            //next char is 0-9
            if(pos+1 < s.size() && s[pos+1] >= '0' && s[pos+1] <= '9'){    // case 8
                ans += help(pos+2);
            }
            //next char is *
            if(pos+1 < s.size() && s[pos+1] == '*'){        // case 10
                ans += 9*help(pos+2);
            }
            
            //consider current * as 2
            //next char is 0-6
            if(pos+1 < s.size() && s[pos+1] >= '0' && s[pos+1] <= '6'){   // case 9
                ans += help(pos+2);
            }
            
            //next char is *
            if(pos+1 < s.size() && s[pos+1] == '*'){    // case 10
                ans = ans + (6*help(pos+2));
            }
        }
        else if(s[pos] == '1' && pos+1 < s.size()){      
            //next char is 0-9
            if(s[pos+1] >= '0' && s[pos+1] <= '9'){ // case 4
                ans += help(pos+2);
            }
            //next char is *
            else if(s[pos+1] == '*'){       // case 6
                ans += 9*help(pos+2);
            }
        }
        else if(s[pos] == '2' && pos+1 < s.size()){
            //next char is 0-6
            if(s[pos+1] >= '0' && s[pos+1] <= '6'){    // case 5
                ans += help(pos+2);
            }
            //next char is *
            else if(s[pos+1] == '*'){     // case 7
                ans += 6*help(pos+2);
            }
        }
        
        //perform mod as and can be large (as given in question)
        ans = ans % m;
        
        //I will remember this result and return the result
        return dp[pos] = ans;
    }
};