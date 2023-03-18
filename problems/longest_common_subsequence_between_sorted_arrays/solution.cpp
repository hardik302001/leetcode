class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        vector<int> ans; 
        unordered_map<int, int> freq; 
        for (auto& array : arrays) 
            for (auto& x : array) 
                if (++freq[x] == arrays.size()) ans.push_back(x); 
        return ans; 
    }
};
