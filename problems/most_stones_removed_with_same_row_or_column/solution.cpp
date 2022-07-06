//see prev dfs soln also, that's OP

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
    

    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        UnionFind uf(n);
        
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    uf.Union(i,j);
                }
            }
        }
        
        // so at end we will have uf.getCOunt() connected groups
        // if we start removing stones, so we will end up having only one stonein each connected group at end.. why bcz, we need maximum no of stones to be removed, so we will remove sequentially stones in each group and at end we will only have uf.count() no of stones left
        
        // therefore , we removed n - uf.getCount() stones..
        return n - uf.getCount();
    }
};