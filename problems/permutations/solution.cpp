// total n! permutuations

// here it is backtracking by refernce
// also see : https://leetcode.com/problems/permutations-ii/submissions/


/*
class Solution {
public:
   // method 1: standard backtracing solution
    vector<vector<int> > permute(vector<int> &num) {  // we are passing num array only ...
        vector<vector<int> > ans;
        permutation(num, 0, ans);
        return ans;
    }

    void permutation(vector<int>& num, int begin, vector<vector<int> > &ans) {        
        //now we are taking nums vector by value, so we need to backtrack it
        if (begin == num.size()) {
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
*/



/*
Time complexity: O(N! * N)

Reason:  The recursion takes O(N!)  time because we generate every possible permutation and another O(N)  time is required to make a deep copy and store every sequence in the data structure. 

Space complexity: O(N) 

Reason: Result stored in a vector, we are auxiliary space taken by recursion
*/


//--------------------------------------------------------------------








class Solution {
public:
    vector<vector<int> > res;
    
    vector<vector<int> > permute(vector<int> &num) {
        int n = num.size();
        map<int , int>m;
        for(auto x: num) m[x]++; 
        vector<int>cur = {};   // keep a new array to keep track of it
        permutation(cur , m , n);

        return res;
    }
    
    
     void permutation(vector<int>&cur , map<int, int>&m , int n) {        
        if(cur.size()==n){
            res.push_back(cur);
            return;
        }
        
         
        for(auto &x: m){
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
/*
Time Complexity:  N! x N

Space Complexity:  O(N)
*/
