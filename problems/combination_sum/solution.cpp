// BBACKTRACKING

class Solution {
public:
    
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<int>temp = {};
        recur(0 , target , temp , cand);
        return ans;
    }
    
    void recur(int ind , int target , vector<int> &temp , vector<int>&cand){
        if(target <0 or ind==(cand.size())){
            return;
        }
           
        if(target==0){
            ans.push_back(temp);
            return;
        }
           
        // target is more than zero , so continue adding more elements
        
        
        // choosing this current index element ( more than 1 times ) !
        temp.push_back(cand[ind]);
        recur(ind , target - cand[ind] , temp , cand);
        temp.pop_back();
           
        // if we dont want to push current element, we go for next element !
        recur(ind+1 , target, temp , cand);
        
    }
    
};
