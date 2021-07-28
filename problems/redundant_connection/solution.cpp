/* This solution is similar to that mentioned in the offical solution. We will construct the graph by adding edges one after another. After each addition of a new edge, we will do a dfs traversal to check if any cycle has formed. If a cycle is detected, we know that the last edge addition has led to the formation of cycle and hence we will simply return that edge.


*/

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
    
    
        bool dfs(vector<vector<int>>& graph, vector<bool>& vis, int cur, int par = -1) {
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