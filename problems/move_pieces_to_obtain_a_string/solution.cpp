// exactly same as: https://leetcode.com/problems/swap-adjacent-in-lr-string/

// L and R cant cross each other, so relative order remains same. 
// they can just roam in empty space according to their direction
// now, we try to match positions fo reach unmatches L and R.
// if index of L in start < index of L in target, we cant match them
// same goes for R
// return false in such case, else return true at end!

class Solution {
public:
    bool canChange(string start, string target) {
        int ls = 0;
        int rs = 0;
        int lt = 0;
        int rt = 0;
        int n = start.size();
        vector<int>s;
        vector<int>t;
        for(auto x: start){
            if      (x=='L')      ls++; 
            else if (x=='R')      rs++;
        }
        
       for(auto x: target){
            if      (x=='L')      lt++;
            else if (x=='R')      rt++;
        }
        
        if(ls!=lt or rs!=rt)      return false;
        
        for(int i= 0;i<n;i++)
            if(start[i]!='_')     s.push_back(i);

        for(int i= 0;i<n;i++)
            if(target[i]!='_')    t.push_back(i);
        
        int sz = s.size();
        for(int i = 0;i<sz;i++){
            if(start[s[i]]!=target[t[i]]){          // different character, as relative order shud be same
                return false;  
            }else{              // it means for every i we have saem s[i] and t[i]
                if(start[s[i]]=='L' and s[i]<t[i]){
                    return false;
                }
                if(start[s[i]]=='R' and s[i]>t[i]){
                    return false;
                }
            }
        }
        
        return true;
    
    }
};