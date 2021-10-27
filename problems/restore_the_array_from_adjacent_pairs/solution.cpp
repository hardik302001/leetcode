/*

It is obvious that the first and the last element appear only once in the pairs,
so we can store all the elements' adjacent elements and we can set up the first and the last element which
the size of adjacent elements is equal to 1.
Next we try to find out 1 ~ n - 1's element,
because we figure out 0-th element, it is easy to know the next one, and so on.
    
*/

class Solution {
public:
    vector<int>adj[200005];
    vector<int>path;
    vector<bool>vis = vector<bool>(200005, false);        //https://chowdera.com/2020/12/202012050445408503.html
    
    void dfs(int src){
    
        vis[src] = true;
        path.push_back(src-100000);
        for(auto node: adj[src]){
            if(!vis[node]){
                dfs(node);
                
            }
        }
    }
    
    vector<int> restoreArray(vector<vector<int>>& adjacent) {
        unordered_map<int, int>m;
        for(auto it: adjacent){
            int u = it[0];
            int v = it[1];
            adj[u+100000].push_back(v+100000);   //bcz our adj is 0 based indexing, so we cant have negative indexes
            adj[v+100000].push_back(u+100000);
            m[u+100000]++;
            m[v+100000]++;
        }
        vector<int>beg;
        for(auto i: m){
            if(i.second&1){
                beg.push_back(i.first);
            }
        }
        
        dfs(beg[0]);
        return path;
   
        
    }
};