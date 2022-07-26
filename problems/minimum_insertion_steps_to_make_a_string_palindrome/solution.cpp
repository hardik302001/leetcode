// if we are allowed insertions at beginning only , then we cant do lps
// Given a string str we need to tell minimum characters to be added at front of string to make string palindrome.
// see for more info : https://www.geeksforgeeks.org/minimum-characters-added-front-make-string-palindrome/#:~:text=Given%20a%20string%20str%20we,and%20'C'%20at%20front.



/*
Approach 1: 
we can also do it using kmp lps concept

Approach 2: 
Take left pointer as 0 and right and n-1 and compare both characters
If both are same left++ and right–;
else
we can think that we have to add N-right elements at front to make last (N-right) characters palindrome so added = (n-right)
Now left again point to 0 as we have to check the string from 0th index .
but while the character at right position is same as 0th index char then we can add one less character at front  and left will increase by 1.
dry run it on :  str = "AACECAAAA"

O(n) solution


int minChar(string str)
{
    // Write your code here
    int n = str.length();
    int left = 0;
    int right = n - 1;
    int added = 0;
    while (left < right) {
        // if left and right characters are same increase
        // left and decrease right pointer
        if (str[left] == str[right]) {
            left++;
            right--;
        }
        // else think of adding some characters at front and
        // start comparing the elements again
        else {
            left = 0;
            added = n - right;
            while (str[left] == str[right]) {
                added--;
                left++;
            }
            right--;
        }
    }
    return added;
}

*/

// -------------------------------------------------------------------------------------------------------

// find LPS
// add the remaining elements
// TC: O(n^2)
class Solution {
public:
    int minInsertions(string s) {
        if(s.empty())
                return 0;

        const int N = s.size();
        // dp(i, j): length of longest palindromic substring in s[i:j]
        vector<vector<int> > dp(N, vector<int>(N, -1)); 
        int lps =  longestPalindSubseqRec(dp, s, 0, N-1);
        return N - lps;
        
    }
    
    int longestPalindSubseqRec(vector<vector<int> >& dp, string& s, int i, int j) {
        if(i > j)
            return 0;
        // when one char
        if(i == j)
            return dp[i][j] = 1;
        
        if(dp[i][j] == -1) {
            if(s[i] == s[j])
                dp[i][j] = 2 + longestPalindSubseqRec(dp, s, i+1, j-1);
            else
                dp[i][j] = max(longestPalindSubseqRec(dp, s, i+1, j), longestPalindSubseqRec(dp, s, i, j-1));
        }
        return dp[i][j];
    }

};