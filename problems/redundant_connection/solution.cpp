//DSU

class Solution {
public:
    
    class UnionFind {
        public:  
            vector<int> parent;
            int count = 0;
            UnionFind(int n){                  //constructor
                count = n;
                parent = vector<int>(n+1,-1);
            }

            int find(int x){
                if(parent[x]==-1) return x;
                return find(parent[x]);
            }

            bool Union(int x,int y){
                int X = find(x);
                int Y = find(y);
                
                if(X==Y) return true;   //cycle found

                parent[Y]=X;
                count--;
                return false;
            }
            

            int getCount(){
                return count;
            }
    };
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
        int n = size(e);
        UnionFind uf(n);           
        for(auto& E : e) {
            if(uf.Union(E[0],E[1])){
                return {E[0],E[1]};
            }
            
        }
        return { };    // un-reachable
    }
        
};


//SEE PREV SOLN ALSO, dfs  , add edge check if there is cycle or not..

/*

//FOR MORE INFO
//https://leetcode.com/problems/redundant-connection/discuss/1295887/Easy-Solution-w-Explanation-or-All-Possible-Approaches-with-comments
class Solution {
public:
    
        vector<int> findRedundantConnection(vector<vector<int>>& e) {
            int n = size(e);
            vector<vector<int>> graph(n+1);
            vector<bool> vis(n+1);                
            for(auto& E : e) {
                fill(begin(vis), end(vis), false);     // reset the vis array
                graph[E[0]].push_back(E[1]), graph[E[1]].push_back(E[0]);
                if(dfs(graph, vis, E[0])) return E;
            }
            return { };    // un-reachable
        }
    
     
        bool dfs(vector<vector<int>>& graph, vector<bool>& vis, int cur, int par = -1) { //check cycle
            vis[cur] = true;
            for(auto child : graph[cur]){
                if(vis[child]==false){
                    if(dfs(graph, vis, child, cur)==true){
                        return true;
                    }
                }
                else{
                    if(child!= par){
                        return true;
                    }
                }
            
            }    
            return false;    // no cycle found
        }


    
};
*/