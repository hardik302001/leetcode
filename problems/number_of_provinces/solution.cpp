// see prev dfs soln also

class Solution {
public:
    class UnionFind {
        public:  
            vector<int> parent;
            int count = 0;
            UnionFind(int n){                  //constructor
                count = n;
                parent = vector<int>(n,-1);
            }

            int find(int x){
                if(parent[x]==-1) return x;
                return find(parent[x]);
            }

            void Union(int x,int y){
                int X = find(x);
                int Y = find(y);

                if(X==Y) return;

                parent[X]=Y;
                count--;
            }

            int getCount(){
                return count;
            }
    };
    
     
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf(n);
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isConnected[i][j])
                   uf.Union(i,j);
            }
        }
        return uf.getCount();
    }
};