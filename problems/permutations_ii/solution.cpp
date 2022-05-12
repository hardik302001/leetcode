// courtesy : NEETCODE PERMUTATION II
// map to avoid count
// better than set solution

class Solution {
public:
    vector<vector<int> > res;
    
    vector<vector<int> > permuteUnique(vector<int> &num) {
        int n = num.size();
        map<int , int>m;
        for(auto x: num) m[x]++; 
        vector<int>cur = {};
        permutation(cur , m , n);

        return res;
    }
    
    
     void permutation(vector<int>&cur , map<int, int>&m , int n) {        
        if(cur.size()==n){
            res.push_back(cur);
            return;
        }
        
         
        for(auto x: m){
            if(x.second>0){
                cur.push_back(x.first);
                m[x.first]-=1;
                    
                permutation(cur , m , n);
                
                m[x.first]+=1;
                cur.pop_back();
            }
        }
         
         
    }

};


// set + perm 1

// class Solution {
// public:
//    // method 1: standard backtracing solution
//     vector<vector<int> > permuteUnique(vector<int> &num) {
//         set<vector<int> > ans;
//         permutation(num, 0, ans);
//         vector<vector<int> > res(ans.begin(),ans.end());
//         return res;
//     }

//     void permutation(vector<int>& num, int begin, set<vector<int> > &ans) {        
//         //now we ar etaking nums vector by value, so we need to backtrack it
//         if (begin >= num.size()) {
//             ans.insert(num);
//             return;
//         }

//         // every number chosen to be the begin once
//         for (int i = begin; i < num.size(); ++i) {
//             swap(num[begin], num[i]);
//             permutation(num, begin+1, ans);
//             swap(num[begin], num[i]);            //backtracking step
//         }
//     }
// };