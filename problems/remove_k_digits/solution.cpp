/*

// SEE PYTHON SOLUTION 
// THAT IS MUCH BETTER, there we keep (n-k) elements
// smalleest subsequence of length (n-k)
// similar to https://leetcode.com/problems/find-the-most-competitive-subsequence/submissions/


// 1st approach!
// remove x elements == maintain (n-x) elements
// nse 

class Solution {
public:
    string removeKdigits(string s, int remove) {
        int n = s.size();
        int k = n - remove;
        stack<int> st;
        for(int i = 0;i<n ; i++){
            while(!st.empty() and st.top()>s[i] and (n-i + st.size())>k){
                st.pop();
            }
            if(st.size()<k){
                st.push(s[i]);
            }
        }
        
        string ans;
        while(!st.empty()){
            int p = st.top();
            ans.push_back(st.top());
            st.pop();
        }
        while(ans.size() and ans.back() == '0'){
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans.size()?ans:"0";
    }
};

*/



// 2nd approach
// cpp soln
// here we try to remove only k elements, we aim to remove k in beginning only, bcz we want lexographically smallest string


class Solution {
public:
    string removeKdigits(string s, int remove) {
        int n = s.size();
        stack<int> st;
        for (auto &it :s ){
            while(!st.empty() and remove and st.top() > it ){
                st.pop();
                remove--;
            }
            st.push(it);
        }
        
        
        while(remove--){
            st.pop();
        }
        
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        while(ans.size() and ans.back() == '0'){
            ans.pop_back();
        }
        
        reverse(ans.begin(),ans.end());
        return ans.size()?ans:"0";
        
    }
};

