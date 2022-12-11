// Claim 1: It is optimal that we make use of all rocks: There is never a benefit of not including a rock in Path 1 or Path 2, it is always positive or neutral.
// Claim 2: It is never optimal to choose two consecutive rocks: If we choose rock_i, and rock_i+1, then rock_i+2 will have to do (rock_i+2)-(rock_i) work to return. Because the array is strictly increasing, it holds that (rock_i+2)-(rock_i) > (rock_i+1-rock_i)
// Therefore one path must lie on each even index and the other path must lie on each odd index. We iterate through them and find the maximum distance.


class Solution {
public:
    int maxJump(vector<int>& stones) {
        int res = stones[1]-stones[0]; // store max difference
        for(int i = 3; i < stones.size(); i+=2) res = max(res, stones[i]-stones[i-2]); // odd path
        for(int i = 2; i < stones.size(); i+=2) res = max(res, stones[i]-stones[i-2]); // even path
        return res;
    }
};




// ----------------------------------------------------------------------
// binary search on answer


/*
class Solution {
public:
    
    bool check(int m , vector<int>stones){
        int n = stones.size();
        vector<bool> visited(n, false);
        
        int ind = 0;
        // Forward Journey
        while (ind < n-1) {
            int j = ind;
            while (j+1 < n && abs(stones[j+1] - stones[ind]) <= m) j ++;
    
            if (j == ind) return false;
            ind = j;
            visited[ind] = true;
        }
        
        // Remove visited indexes to avoid increasing the time complexity :)
        vector<int> indexes;
        for (int j = 0; j < n-1; j ++) {
            if (visited[j] == false) indexes.push_back(j);
        }
        indexes.push_back(n-1);
                
        ind = indexes.size() - 1;
        // Backward Journey
        while (ind > 0) {
            int j = ind;
            while (j > 0 && abs(stones[indexes[j-1]] - stones[indexes[ind]]) <= m) j--; 
            
            if (j == ind) return false;
            ind = j;
        }
        
        return true;
        
        
    }
    
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int l = 0;
        int r = stones.back()-stones[0]+1;
        for(int i = 0;i<n-1;i++){
            int l = max(l , abs(stones[i] -stones[i+1]));
        }
        
        
        if(n<=3){
            return r-1;
        }
        int ans = -1;
        while(l<r){
            int m = l + (r-l)/2;
            if(check(m, stones)){
                ans = m;
                r = m;
            }else{
                l = m+1;
            }
        }
        
        return ans;
    }
};

*/