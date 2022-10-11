// idea : https://www.youtube.com/watch?v=_8hSyaxVRZ8


class Solution {
public:
    int dp[101][101][101];   // l , r , count
    
    // l, r included
    int recur(int l , int r , int c, vector<int>& boxes){
        if(l>r) return 0;

        while(l+1<=r and boxes[l]==boxes[l+1]){
            c+=1;
            l+=1;
        } 
        
        c+=1;   // bcz initially c = 0, we need count of elements
        // c denotes count of continous equal element subarray
        
        
        // use memoised value here, bcz we have to first update value of c for this iteration 
        if(dp[l][r][c]!=-1) return dp[l][r][c];
        
        int ans = recur(l+1, r, 0, boxes) + c*c;
       
        for(int i = l+1;i<=r;i++){
            if(boxes[l]==boxes[i]){ // consider all occurence of breakings
                int middle =  recur(l+1, i-1, 0, boxes);
                int nextPartition = recur(i, r, c, boxes);  // here count is c, not 0
                // we are continuing the previous chain of that eleement only and adding output
                // from middle part to it
                ans = max(ans , middle + nextPartition);       
            }
        }
        
        return dp[l][r][c] = ans;
        
    }
    
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        memset(dp , - 1, sizeof dp);
        return recur(0, n-1, 0, boxes);
    }
};