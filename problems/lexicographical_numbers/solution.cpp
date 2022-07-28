class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        helper(1, n, res);
        return res;
    }
    
    void helper(int target, int n, vector<int>& res) {
        if (target > n) return;
        res.push_back(target);
        helper(target * 10, n, res);
        if (target % 10 != 9) helper(target+1, n, res);  // bcz after 9 , we will have 10, and we have already seen 10
        // even if 10 is not seen, we need 1 first, then we need 10
    }
};
