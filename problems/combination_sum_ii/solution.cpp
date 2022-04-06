// https://leetcode.com/problems/combination-sum-ii/discuss/1277764/Combination-Sum-I-II-and-III-%2B-Subsets-I-and-II-%2B-Permutations-I-and-II%3A-One-stop-C%2B%2B-solutions



// also see prev submisions
class Solution {
public:
    
    void recur(int i, int target , vector<int>&temp , vector<int>&cand, set<vector<int>>&ans){
        if(target<0) return;
        if(target==0){
            ans.insert(temp);
            return;
        }
        
        if(i>=cand.size()) return;
        if(cand[i]>target) return;
        // consider and move to next
        temp.push_back(cand[i]);
        recur(i+1 , target-cand[i] , temp , cand , ans);
        temp.pop_back();
        
        
        while(i<cand.size()-1 and cand[i]==cand[i+1]) i++;
        // move to next unique: ignore current
        recur(i+1 , target , temp , cand , ans);
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        set<vector<int>>ans;
        sort(cand.begin(), cand.end());
        vector<int>temp;
        recur(0 , target , temp , cand , ans);
        vector<vector<int>> res;
        for(auto v: ans){
            res.push_back(v);
        }
        return res;
    }
};
