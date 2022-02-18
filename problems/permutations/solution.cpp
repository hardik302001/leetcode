//total n! permutuations
//see prev submission, for backtracking by copy

// here it is backtracking by refernce


class Solution {
public:
   // method 1: standard backtracing solution
    vector<vector<int> > permute(vector<int> &num) {  // we are passing num array only ...
        vector<vector<int> > ans;
        permutation(num, 0, ans);
        return ans;
    }

    void permutation(vector<int>& num, int begin, vector<vector<int> > &ans) {        
        //now we ar etaking nums vector by value, so we need to backtrack it
        if (begin >= num.size()) {
            ans.push_back(num);
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