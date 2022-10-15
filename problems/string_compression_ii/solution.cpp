// dp , not greedy


int dp[101][27][101][101];
class Solution {
public:

    int recur(string &s , int ind , int prevChar , int prevCount , int k){
        int n = s.size();
        if(k<0)     return 1000;
        if(ind>=n)  return 0;
     
        if(dp[ind][prevChar][prevCount][k]!=-1) return dp[ind][prevChar][prevCount][k];
     
        int del = recur(s, ind+1 , prevChar , prevCount, k-1);
        int keep;
        int curChar = s[ind]-'a';
        if(curChar==prevChar){
            keep = recur(s , ind+1, prevChar, prevCount+1, k);
            if(prevCount==1 or prevCount==9 or prevCount==99) keep++;
        }else{
            keep = 1 + recur(s , ind+1, curChar , 1, k);
        }
        
        return (dp[ind][prevChar][prevCount][k] = min(del , keep));
    }
    
    
    int getLengthOfOptimalCompression(string s, int k) {
         memset(dp, -1, sizeof(dp));
        return recur(s, 0 , 26 , 0 , k);
        
        // 26 for prevChar bcz we have lowercase s ascii from (0 to 25), therefore we can distimguish between them 
    }
};