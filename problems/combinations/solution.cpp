class Solution {
public:
    
    vector<vector<int>>ans;
    
    void recur(int x  ,int n ,  vector<int>&cur, int k){
        if(cur.size()==k) {
            ans.push_back(cur);
            return;
        }
        if(x>n) return;
    
        
        // consider
        cur.push_back(x);
        recur(x+1 , n, cur , k);
        cur.pop_back();
        
        
        // ignore
        recur(x+1, n , cur , k);
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int>cur = {};
        recur(1 , n, cur , k );
        return ans;
    }
};