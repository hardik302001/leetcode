// also see python solution
// size k = maintain size k





// size k == removing (n-k) elements
// very similar to : https://leetcode.com/problems/remove-k-digits/submissions/            cpp solution


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