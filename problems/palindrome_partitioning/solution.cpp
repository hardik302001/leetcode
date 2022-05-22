// there is also a dp optimised solution, do that also in future!
// I have not done that

// TC : O(n* 2^n)
// SC : O(n)


class Solution {
public:
    vector<vector<string> > res;
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        backtrack(0, temp,  s);
        return res;
    }
    
    void backtrack(int start, vector<string> &temp, string s){
        int n = s.length();
        if (start == n) {
            res.push_back(temp);
            return;
        } 
    
        for (int i = start; i < n; i++) {
            if (isPalindrome(s, start, i)) {  // we are only pushing palindromes 
                // cout<<start<<i<<s.substr(start, i - start + 1)<<endl;
                temp.push_back(s.substr(start, i - start + 1));
                backtrack( i + 1, temp, s);
                temp.pop_back();     //bcz we can have more palindromes also after index start
            }
        }
        
    }
    
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }    
};


/*

Time Complexity: O( (2^n) *k*(n/2) )
Reason: O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. O(k) is for inserting the palindromes in another data structure, where k  is the average length of the palindrome list.

Space Complexity: O(k * x)
Reason: The space complexity can vary depending upon the length of the answer. k is the average length of the list of palindromes and if we have x such list of palindromes in our final answer. The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n).
*/

