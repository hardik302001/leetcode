class Solution {
public:
     class UnionFind {
        public:  
            vector<int> parent;
            int count = 0;
            UnionFind(int n){                  //constructor
                count = n;
                for(int i = 0;i<=(n+1);i++){    //path compression
                    parent.push_back(i);
                }
            }

            int find(int x){
                if(parent[x]==x) return x;
                return parent[x] = find(parent[x]);
            }

            void Union(int x,int y){
                int X = find(x);
                int Y = find(y);
                
                // if(X==Y) return true;   //cycle found

                parent[Y]=X;
                count--;
                // return false;
            }
            

            int getCount(){
                return count;
            }
    };
    
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf(26);
        vector<string>accept;
        vector<string>reject;
        for(auto &st: equations){
            char eq = st[1];
            if(eq=='='){
                accept.push_back(st);
            }else{
                reject.push_back(st);
            }
        }
        
        for(auto &st: accept){
            char a = st[0];
            char b = st[3];
            uf.Union(a-'a',b-'a');
        }

        for(auto &st: reject){
            char a = st[0];
            char b = st[3];
            if(uf.find(a-'a')==uf.find(b-'a')){
                return false;
            }
        }
        
        
        
        return true;
    }
};