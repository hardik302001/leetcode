// exactly same as: https://leetcode.com/problems/move-pieces-to-obtain-a-string/submissions/

class Solution {
public:
    bool canTransform(string start, string target) {
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
            if(start[i]!='X')     s.push_back(i);

        for(int i= 0;i<n;i++)
            if(target[i]!='X')    t.push_back(i);
        
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