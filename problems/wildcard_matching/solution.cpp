// also see: https://leetcode.com/problems/regular-expression-matching/




// recursion

// TC: 2^(m+n)

/*
class Solution {
public:
    bool isMatch(string s, string p) {
        int i=0, j=0;
        
        //i is pointer on s
        //j is pointer on p
        return fun(s,p,i,j);
    }
    
    bool fun(string& s, string& p, int i, int j){
        //1. Base case
        //a. String p has ended - s must have ended for a match between them.
        if(i == s.size() and j==p.size()) return true;
        
        //b. String s has ended - p[j] could only be '*' or multiple '*' for a match.
        if(i==s.size()) return (p[j] == '*' && fun(s,p,i,j+1));
        
        //2. If none of them has ended and p[j] is '*', nothing can be said before comparing rest of the strings, both of them.
        if(p[j] == '*') return fun(s,p,i+1,j) or fun(s,p,i,j+1);
        
        //3. Else, when p[j] = '?' or a character - If it is a character it must be same as s[i]
        else{
            bool sameChar = i<s.size() && (p[j] == s[i] || p[j] == '?');
            return (sameChar && fun(s,p,i+1,j+1));
        }
    }
};

*/


// dp memoised
// O(n*m)
class Solution {
public:
    bool match(string& s, string& p, int i, int j, vector<vector<int>>& v){
        if(i==s.size()&&j==p.size())
            return true;
        else if(i==s.size()) 
            return (p[j]=='*'&& match(s,p,i,j+1,v));
        else if(j==p.size())
            return false;
        
        if(v[i][j]!=-1) return v[i][j];
        
        if(p[j]=='*')
            return v[i][j]= (match(s,p,i,j+1,v)||match(s,p,i+1,j,v));
        
        if(p[j]=='?'||s[i]==p[j])
            return v[i][j] = match(s,p,i+1,j+1,v);
        
        return false;
    }
    
    bool isMatch(string s, string p) {
       vector<vector<int>> v(s.size(), vector<int>(p.size(), -1));  
       return match(s,p,0,0,v);
    }
};