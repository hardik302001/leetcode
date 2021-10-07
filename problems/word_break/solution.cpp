//O(n3)

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        
        int n = s.size();
        if(dict.size()==0) return false;
        
        vector<bool> dp(n+1,false);
        dp[0]=true;

        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    cout<<word<<endl;
                    
                    if(dict.find(word) != dict.end())
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }

        return dp[n];
    }
};

// l
// le
// lee
// leet
// c
// leetc
// co
// leetco
// cod
// leetcod
// code

// All the lines below won't run b/c of break;
// Index 4 is a valid start index, and index 4 - index 7 make up the word `code`
// We can break once we've found any connecting word because
// all we're trying to do is find SOME valid way to connect to s[i].
// Once we've found SOME word that does that, there's no need to continue checking.
//    -----
//   ------
//  -------
// --------