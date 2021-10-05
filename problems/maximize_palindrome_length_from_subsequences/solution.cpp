//first see 
//
//
//https://leetcode.com/problems/longest-palindromic-subsequence/
//
//
//then come here











class Solution {
public:
    int lps(string s,  vector<vector<int>> &dp) {
        int size=s.size();
        if(size==1){
            return 1;
        }
        //GAP METHOD
        for(int gap=0;gap<size;gap++){
            int row = 0;
            for(int col=gap;col<size;col++){
                if(gap==0){
                    dp[row][col]=1;
                }
                else if(gap==1){
                    dp[row][col]= (s[row]==s[col]) ? 2 : 1;
                }
                else{
                    if(s[row]==s[col]){
                        dp[row][col]=2+dp[row+1][col-1];
                    }
                    else{
                        //prefix and suffix
                        dp[row][col]=max(dp[row][col-1],dp[row+1][col]);
                    }
                }
                
                row++;
            }
        }
        return dp[0][size-1];
    }
int longestPalindrome(string w1, string w2) {
    int sz = w1.size() + w2.size(), res = 0;
    vector<vector<int>> dp(sz, vector<int>(sz));
    lps(w1 + w2, dp);
    // for(int i = 0;i<sz;i++){
    //     for(int j = 0;j<sz;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    
    
    
    
    //we calculated lps for syriing s = w1 + w2
    //print its dp array by uncommenting it
    //dp[i:j] gives lps for substring s[i:j]
    
    //so we need a non empty subsequence from both both strings
    //it means , we need to consider only those subsequences that have atleast one one character from both strings....and choose longest length out of them
    
    //but how to check if a palindrome is made from bth stings..?
    //we will consider a barrier , suppose x
    //and from taht aplindrome subseq we will check that atleast one the equal chacrter should be less than x, and other should be >= x..
    
    // palindromic subseq = " bacab"... so for evry equal eleemnt pair, we will check if :
    //                        b   | a c a b
    //                        b a | c a b
    //  so we are chceking if both "b " are on either side of x
    //  so we are chceking if both "a " are on either side of x
    // but what should be x, welll x should be ending point of first string..why ?? tahts very obvious..ten only we can have elements in both strings(non empty subsequnce from both strings..)
    
    // for more info: visit cherry coder [IITG] youtube titled same as this problem video 
    
    for (int i = 0; i < w1.size(); ++i)
        for (int j = 0; j <w2.size(); j++)  
            
            if (w1[i] == w2[j]) {
                res = max(res, dp[i][w1.size() + j]); //we will only check in first quad(all positive trigno function) , w1 only  y axis , w2 on x axis..
            }
    //watch pepcoding lps video to understand what we are doing above, the last 10 minutes of that 40 mins video..
    // print dp array and see what we are doing in this above loop..
    
    
    return res;
    }
};