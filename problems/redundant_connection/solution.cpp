//DSU
//SEE PREV SOLN ALSO, dfs


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