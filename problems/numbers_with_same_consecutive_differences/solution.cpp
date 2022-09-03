// TC = O(2^n)
// backtracking

// concise version of below code

class Solution {
public:
    
    vector<int>ans;
    
    void backtrack(int ind , int n , int k, int &cur){
        if(ind==n){
            ans.push_back(cur);
            return;
        }
        
        for(int i = 0;i<=9;i++){
            if(i==0 and ind==0) continue;      // first index, no leading zeros
            int x = cur%10 ;
            if(abs(x-i)!=k and cur) continue;  // early breaking  
            cur = 10*cur + i;            
            backtrack(ind +1 , n , k , cur);
            cur = cur/10;
            
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        int cur = 0;
        backtrack(0, n , k , cur);
        return ans;
    }
    
};


// ----------------------------------------------------------------------
/*
// TC = O(2^n)

class Solution {
public:
    
    vector<int>ans;
    
    void backtrack(int ind , int n , int k, int &cur){
        if(ind==n){
            ans.push_back(cur);
            return;
        }
        
        for(int i = 0;i<=9;i++){
            if(i==0 and ind==0) continue;      // first index, no leading zeros
            if(ind==0){                        // from 1 to 9
                cur += i;
                backtrack(ind +1 , n , k , cur);
                cur-=i;
            }else{
                int x = cur%10 ;
                if(abs(x-i)==k){                // condition chekcing
                    cur = 10*cur + i;            
                    backtrack(ind +1 , n , k , cur);
                    cur = (cur - i)/10;
                }
            }
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        int cur = 0;
        backtrack(0, n , k , cur);
        return ans;
    }
    
};
*/