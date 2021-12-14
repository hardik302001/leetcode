

// SEE PYTHON SOLUTION 
// THAT IS MUCH BETTER, there we keep (n-k) elements
// smalleest subsequence of length (n-k)
// similar to https://leetcode.com/problems/find-the-most-competitive-subsequence/submissions/



// here we try to remove only k elements, we aim to remove k in beginning only, bcz we want lexographically smallest string
//this is also nice code
class Solution {
public:
    string removeKdigits(string num, int k) {
       string ans = "";                                         // treat ans as a stack in below for loop
       
       for (char c : num) {
           while (ans.length() && ans.back() > c && k) {
               ans.pop_back();                                  // make sure digits in ans are in ascending order
               k--;                                             // remove one char
           }
           
           if (ans.length() || c != '0') { ans.push_back(c); }  // can't have leading '0', beautiful logic to find it! if ans is empty and  c=='0', then it wont push..else it would push irrespevtiv eof value of c
        }
       
       while (ans.length() && k--) { ans.pop_back(); }          // make sure remove k digits in total
       
       return ans.empty() ? "0" : ans;
    }
};