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
    
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        UnionFind uf(n);
        for(auto &p: connections){
            uf.Union(p[0],p[1]);
        }
        
        if(connections.size()>=(n-1)){
            return uf.getCount()-1;
        }
        
        return -1;
    
    }
};