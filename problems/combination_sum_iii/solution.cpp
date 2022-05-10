// bitmask

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        
        for(int mask = 0;mask<(1<<9);mask++){
            vector<int>temp;
            for(int j = 0;j<9;j++){   // size of bitmask(2^9)
                if(mask&(1<<j)){
                    temp.push_back(j+1);
                }
            }
            int sum = accumulate(temp.begin(), temp.end() , 0);
            if(sum==n and temp.size()==k){
                res.push_back(temp);
            }
        }
        
        return res;
    }
};


/*
// backtracking

class Solution {
public:
    vector<vector<int>>ans;
    
    void recur(int cur , int n , int k , vector<int>&temp){
        if(k<0) return;
        if(n<0) return;

        if(k==0 and n==0){
            ans.push_back(temp);
            return;
        }
        if(cur>9) return;
        
        // consider current and move to next
        temp.push_back(cur);
        recur(cur+1 , n-cur , k-1, temp);
        temp.pop_back();
            
        // ignore current and move to next        
        recur(cur+1 , n , k, temp);
                    
        
    }
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n<k*(k+1)/2){return {};}
 
        if (((9)*(10)/2 - (9-k)*(9-k+1)/2 ) <n){
            return {};
        }
        vector<int>temp;
        recur(1 , n , k , temp);
            
        return ans;
    }
};
*/


// similar soln
/*
class Solution {
public:
    vector<vector<int>>ans;
    
    void recur(int cur , int n , int k , vector<int>&temp){
        if(k<0) return;
        if(n<0) return;
        if(k==0 and n==0){
            ans.push_back(temp);
            return;
        }
        for(int i = cur; i<10 ;i++ ){
            temp.push_back(i);
            recur(i+1 , n-i , k-1, temp);
            temp.pop_back();
            
        }        
        
    }
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n<k*(k+1)/2){return {};}
 
        if (((9)*(10)/2 - (9-k)*(9-k+1)/2 ) <n){
            return {};
        }
        vector<int>temp;
         recur(1 , n , k , temp);
            
        return ans;
    }
};
*/