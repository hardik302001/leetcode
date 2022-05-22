// https://leetcode.com/problems/combination-sum-ii/discuss/1277764/Combination-Sum-I-II-and-III-%2B-Subsets-I-and-II-%2B-Permutations-I-and-II%3A-One-stop-C%2B%2B-solutions



// also see prev submisions
class Solution {
public:
    
    void recur(int i, int target , vector<int>&temp , vector<int>&cand, vector<vector<int>>&ans){
        if(target<0) return;
        if(target==0){
            ans.push_back(temp);
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
        vector<vector<int>>ans;
        sort(cand.begin(), cand.end());
        vector<int>temp;
        recur(0 , target , temp , cand , ans);
        
        return ans;
    }
};

/*
Time Complexity:O(2^n*k)
Reason: Assume if all the elements in the array are unique then the no. of subsequence you will get will be O(2^n). we also add the ds to our ans when we reach the base case that will take “k”//average space for the ds.

Space Complexity:O(k*x)
Reason: if we have x combinations then space will be x*k where k is the average length of the combination.

*/