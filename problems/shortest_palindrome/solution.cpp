/*
we need to find the longest palindrome substring!

we did it by strng matching O(n2) see last soln, we will optimise it by kmp in this soln!
Courtesy : ideserve channel : youtube video SHORTEST PALINDROME

*/


class Solution {
public:
    
    vector<int> prefix_function(string s) {
        int n = (int)s.length();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }
    
    string shortestPalindrome(string s) {
        int n = s.size();
        if(s==""){
            return s;
        }
        
        string rev = string(s.rbegin(),s.rend()); 
        string check = s +"#"+ rev;
        vector<int> pi = prefix_function(check);
        int longest_palin = pi[(2*n+1)-1];     //redundant variable
        string front = string(rev.begin(), rev.begin()+n - longest_palin);
        string res = front + s;
        return res;
    }
};