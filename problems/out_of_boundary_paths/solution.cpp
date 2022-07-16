class Solution {
public: 
   int mx=1e9+7; //used to take modulo 

    // 3 states, moves, x coord , y coord
   
    int find(int m, int n, int N, int i, int j,vector<vector<vector<int>>> &memo)
   { 
       if(i<0||j<0||i>=m||j>=n) return 1; //Outside the grid  
       if(N==0) return 0;                 //if we are inside the grid and we have no moves 
       if(memo[N][i][j]!=-1) return memo[N][i][j]; //if we have already result of this state, return this
       vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}}; //used to visit all 4 directions
       int res=0;  //final result
       for(auto x:dir) //visit all 4 directions
       {
           /*
             Here we have taken a move , hence next time our move will be (N-1)
             And after taking a move we will reach (i+1,j),(i-1,j),(i,j+1),(i,j-1)
             Store the count when we will reach to boundary, 
             If we will reach outside grid , it will return 1
             else return 0;
           */
           res+=find(m,n,N-1,i+x[0],j+x[1],memo); 
           res%=mx;
       }
       return memo[N][i][j]=res%mx; //return the final answer after taking modulo,store it in this state
   }
   
   int findPaths(int m, int n, int N, int i, int j) {
       //Here I have taken 3-d vector , because there are three states in function N,i,j
       vector<vector<vector<int>>> memo(N+1,vector<vector<int>> (m,vector<int>(n,-1)));
       return find(m,n,N,i,j,memo);
   }
};


// TC: o(m*n*Moves)