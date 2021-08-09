class Solution {
public:
   // method 1: standard backtracing solution
    vector<vector<int> > permuteUnique(vector<int> &num) {
        set<vector<int> > ans;
        permutation(num, 0, ans);
        vector<vector<int> > res(ans.begin(),ans.end());
        return res;
    }

    void permutation(vector<int>& num, int begin, set<vector<int> > &ans) {        
        //now we ar etaking nums vector by value, so we need to backtrack it
        if (begin >= num.size()) {
            ans.insert(num);
            return;
        }

        // every number chosen to be the begin once
        for (int i = begin; i < num.size(); ++i) {
            swap(num[begin], num[i]);
            permutation(num, begin+1, ans);
            swap(num[begin], num[i]);            //backtracking step
        }
    }
};