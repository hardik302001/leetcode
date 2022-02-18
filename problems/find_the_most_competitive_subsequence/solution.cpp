// 1st approach!
// size k = maintain size k
// nse 

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        stack<int> st;
        for(int i = 0;i<n ; i++){
            while(!st.empty() and st.top()>nums[i] and (n-i + st.size())>k){
                st.pop();
            }
            if(st.size()<k){
                st.push(nums[i]);
            }
        }
        
        vector<int>ans;
        while(!st.empty()){
            int p = st.top();
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


// 2nd approach
// cpp soln
// size k == removing (n-k) elements
// very similar to : https://leetcode.com/problems/remove-k-digits/submissions/            cpp solution
// https://leetcode.com/problems/find-the-most-competitive-subsequence/
// nse
/*
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        int remove = (n-k);
        stack<int> st;
        for (auto &it : nums ){
            while(!st.empty() and remove and st.top() > it ){
                st.pop();
                remove--;
            }
            st.push(it);
        }
        
        
        while(remove--){
            st.pop();
        }
        
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};

*/