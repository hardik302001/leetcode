// exactly same as: https://leetcode.com/problems/permutations-ii/
// just do sqaure checking on the spot before pushing into cur , 

// if you make res, then seperately do it , then its bs , and eventually lead to TLE 

class Solution {
public:
     vector<vector<int> > res;
     void permutation(vector<int>&cur , map<int, int>&m , int n) {        
        if(cur.size()==n){
            res.push_back(cur);
            return;
        }
        
         
        for(auto &x: m){
            if(x.second>0){
                if(cur.size()){
                    if(!is_perfect_sq(cur.back() + x.first)){
                        continue;
                    }
                }
                cur.push_back(x.first);
                m[x.first]-=1;
                    
                permutation(cur , m , n);
                
                m[x.first]+=1;
                cur.pop_back();
            }
        }   
    }
    
    bool is_perfect_sq(int n){
        int x =  sqrt(n);
        return x*x == n;
    }

    int numSquarefulPerms(vector<int>& num) {
        int n = num.size();
        map<int , int>m;
        for(auto x: num) m[x]++; 
        vector<int>cur = {};
        permutation(cur , m , n);
        
        return res.size();

    }
    
    
};