// M coloring : https://practice.geeksforgeeks.org/viewSol.php?subId=fa320224e5f691d6214b957417fdb45e&pid=701374&user=shardik2001

// O(m^V) : TC
// also see: bfs soln

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int>color(n, 0);  // bcz 0 is not any color
        // all m colors start from 1 to m
        int m = 4;
        vector<vector<int>>adj(n);
        for(int i = 0;i<paths.size();i++){
            paths[i][0]-=1;
            paths[i][1]-=1;
            adj[paths[i][0]].push_back(paths[i][1]);
            adj[paths[i][1]].push_back(paths[i][0]);
        }
        solve(0 , adj , m , n, color);
        return color;
    }
    
    

    int solve(int node , vector<vector<int>>&adj , int m , int n, vector<int>&color){
        if(node==n)return 1;    // we sucessfully covered all nodes

        for(int col = 1; col<=m ; col++){  // try all colors on node
            if(safe(col , node, adj , n, color)){
                color[node] = col;
                if(solve(node+1 , adj , m , n, color)){
                    return 1;
                }else{
                    color[node] = 0;
                }

            }
        }

        return 0; // none of color worked
    }

    bool safe(int col , int node , vector<vector<int>>&adj , int n, vector<int>&color){
        for(auto nei: adj[node]){
            if(color[nei]==col){
                return false;
            }
        }
        return true;
        
    }

    
};
