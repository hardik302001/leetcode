// knapsack dp

// void return type

// class Solution {
// public:
//     int maxi = 0;
//     void recur(int i , int z , int o , int m , int n , int c , vector<string>& strs){
//         if(z<=m and o<=n){
//              maxi = max( maxi , c);
//         }
//         if(i==strs.size()) return; 
        
//         int x = 0;
//         int y = 0;
//         for(auto ele: strs[i]){
//             if(ele== '0') x++;
//             else         y++;
//         }
        
//         recur(i+1 , z, o , m ,n , c, strs);
        
//         if(z+x<= m and o+y<=n) {
//             recur(i+1 , z+x , o+y , m , n , c+1 , strs); 
//         }

//     }
    
    
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         recur(0 , 0 , 0 , m , n , 0 , strs );
//         return maxi;
//     }
// };


/* -------------------------------------------------------------------------------- */ 

// int return type recursion

// class Solution {
// public:
    
//     int recur(int i , int z , int o , int m , int n , vector<string>& strs){

//         if(i==strs.size()) return 0; 
        
//         int x = 0;
//         int y = 0;
//         for(auto ele: strs[i]){
//             if(ele== '0') x++;
//             else          y++;
//         }
        

//         if(z+x<= m and o+y<=n) {
//             return max(1 + recur(i+1 , z+x , o+y , m , n , strs) ,  recur(i+1 , z, o , m ,n , strs)); 
//         }else{
//             return  recur(i+1 , z, o , m ,n, strs);
//         }
//     }
    
    
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         return recur(0 , 0 , 0 , m , n , strs );
//     }
// };



/* -------------------------------------------------------------------------------- */ 


// 01 KNAPSACK DP
// 3D DP
// Also see: bottom up , thats a 2D dp  : https://leetcode.com/problems/ones-and-zeroes/discuss/1138589/Short-and-Easy-w-Explanation-or-O(L*m*n)-DP-solution-(6-lines)-similar-to-knapsack

class Solution {
public:
    int dp[601][101][101];
    int recur(int i , int z , int o , int m , int n , vector<string>& strs){

        if(i==strs.size()) return 0; 
        if(dp[i][z][o]!=-1) return dp[i][z][o];
        int x = 0;
        int y = 0;
        for(auto ele: strs[i]){
            if(ele== '0') x++;
            else          y++;
        }
        
        if(z+x<= m and o+y<=n) {
            return dp[i][z][o] = max(1 + recur(i+1 , z+x , o+y , m , n , strs) ,  recur(i+1 , z, o , m ,n , strs)); 
        }else{
            return dp[i][z][o] =   recur(i+1 , z, o , m ,n, strs);
        }
        
        
    }
    
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp , -1 , sizeof(dp));
        return recur(0 , 0 , 0 , m , n , strs );
    }
};