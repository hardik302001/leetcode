// BACK TRACKING
// https://leetcode.com/submissions/detail/643040377/

// see prev submissions also

class Solution {
public:
    
    void recur(int i, int target , vector<int>&temp , vector<int>&cand, set<vector<int>>&ans){
        if(target<0) return;
        if(target==0){
            ans.insert(temp);
            return;
        }
        
        
        if(i>=cand.size()) return;
        
        // conisider and go for next
        
            temp.push_back(cand[i]);
            recur(i+1 , target-cand[i] , temp , cand , ans);
            temp.pop_back();
            
        // consider and stay at current element 
            
            temp.push_back(cand[i]);
            recur(i , target-cand[i] , temp , cand, ans);
            temp.pop_back();
            
        // dont conisider and move for next
            recur(i+1 , target , temp , cand, ans);
            
                    
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        set<vector<int>>ans;
    
        vector<int>temp;
        recur(0 , target , temp , cand , ans);
        vector<vector<int>> res;
        for(auto v: ans){
            res.push_back(v);
        }
        return res;
    }
};
