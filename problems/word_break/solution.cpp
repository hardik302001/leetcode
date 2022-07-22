// brute force  :::: Given an array of length n, there are n+1 ways/intervals to partition it into two parts. Each interval has two choices - split or not. In the worse case, we will have to check all possibilities, which becomes O(2^(n+1)) -> O(2^n). This analysis is similar to palindrome partitioning


/*
// DP (O(n^3)) => n for traversal , n for recursion , n for checking in dict

Step 1: Create set named dictionary. Set will help to get all words in sorted order.
Step 2: Declare dp vector of integers of size n (size of given string).
dp[i] will denote if string from i...n-1 can be broken into valid parts or not.
Initially dp[i] is -1. It means we do not know whether it can be broken or not.
Step 3: Call recursiveSoln function.
Step 4: How recursiveSoln function works?
Suppose string from i...n-1 is: aabc
Then it will one by one partition like: (a abc), (aa bc), (aab c), (aabc ).
And if partition is valid ,then it will call recursiveSoln function for remaining string.
(Suppose "a" is present in dictionary, then it will check for "abc").
Step 5: We can get to same index again:
For example : string s="aabd" can be partitioned like:
["a","a","bd"] , ["aa","bd"]. We are reaching to same string again.
So we are storing result in dp after calculating for first time.
*/

class Solution {
public:
    bool recursiveSoln(int index,string &s,set<string>&dictionary,vector<int>&dp){
        if(index>=s.size()){
            return true;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        
        string part;
        
        for(int i=index;i<s.size();i++){
            part.push_back(s[i]);
            
            if(dictionary.find(part)!=dictionary.end() and recursiveSoln(i+1,s,dictionary,dp)){
                //Word found and //Checking for remaining string
                return dp[index]=true; //found the way of partitioning
            }
        }
        return dp[index]=false; //Checked all possible ways but can't break into valid parts.
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>dictionary;
        for(auto &word:wordDict){
            dictionary.insert(word);
        }
        vector<int>dp(s.size(),-1);
        return recursiveSoln(0,s,dictionary,dp);
    }
};


// similar thing using trie: https://leetcode.com/problems/word-break/discuss/1556777/C%2B%2B-or-MEMOIZATION-%2B-TRIE-or-NO-HASHMAP-or-O(N3)-TIME


