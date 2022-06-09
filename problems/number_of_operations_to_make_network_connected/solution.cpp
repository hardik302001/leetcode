// you need not count extra edges (or cycles),
// you only need to count total number of components... bcz if we have sufficient edges, then we need minimum of k-1 edges for k components..
// ans = component_count - 1

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
    
    
    int makeConnected(int n, vector<vector<int>>& con) {
        UnionFind uf(n);
        if (n-1>con.size()) return -1;
        int c = 0;
        for(auto &p: con){
            uf.Union(p[0],p[1]);
        }
        
        return uf.getCount()-1;

    
    }
};

// dfs

/*
class Solution {
private:
    void dfs(vector<vector<int>> &adj, vector<bool> &visited, int src)
    {
        visited[src] = true;
        for(int i : adj[src])
            if(!visited[i])
                dfs(adj, visited, i);
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n - 1)
            return -1;
        vector<vector<int>> adj(n);
        for(auto v : connections)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<bool> visited(n, false);
        int components = 0;
        for(int i=0; i<n; i++)
            if(!visited[i])
            {
                dfs(adj, visited, i);
                components++;
            }
        return components - 1;
    }
};

*/