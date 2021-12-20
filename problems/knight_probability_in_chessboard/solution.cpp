// also see https://leetcode.com/problems/out-of-boundary-paths/  


// supreme code
class Solution {
public:
    double find(int n, int K, int i, int j,vector<vector<vector<double>>> &memo)
   { 
       if(i<0||j<0||i>=n||j>=n) return 0; //Outside the grid  
       if(K==0) return 1;                 //if we are inside the grid and we have no moves 
       if(memo[K][i][j]!=-1) return memo[K][i][j]; //if we have already result of this state, return this
       
       vector<vector<int>> dir={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}}; //used to visit all 8 directions
       double res=0;  //final result
       for(auto x:dir) //visit all 4 directions
       {
           res+=find(n, K-1,i+x[0],j+x[1],memo); 
       }
        
        res = res/8;  // bcz we are choosing one path out of 8 paths!
        
       return memo[K][i][j]=res; //return the final answer after taking modulo,store it in this state
   }
    
    
    double knightProbability(int n, int K, int i, int j) {
        vector<vector<vector<double>>> memo(K+1,vector<vector<double>> (n,vector<double>(n,-1)));
       return find(n,K,i,j,memo);
    }
};
