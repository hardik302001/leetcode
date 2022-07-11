// Kruskal , O(ElogV)
class Solution {
public:
    
    class UnionFind {
        public:  
            vector<int> parent;
            int count = 0;
            UnionFind(int n){                  //constructor
                count = n;
                for(int i = 0;i<=(n);i++){    //path compression
                    parent.push_back(i);
                }
            }

            int find(int x){
                if(parent[x]==x) return x;
                return parent[x] = find(parent[x]);
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
    

    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        UnionFind uf(n);
        priority_queue< vector<int> , vector<vector<int>> , greater<vector<int>> > minpq;        // min heap
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                minpq.push( {abs( points[i][0] - points[j][0]) + abs( points[i][1] - points[j][1]), i , j});
            }
        }
        
        int ans = 0;
        int edges_count = 0;
        while(minpq.size()>0){
            if(edges_count==(n-1)){break;}     // very important!! KEEP COUNTER , else you get TLE , break when you get (n-1) edges..no need to go till end
            
            auto topa = minpq.top();
            minpq.pop();
            if(!uf.Union(topa[1], topa[2])){  // not already connected, so connect them and fuck it mann
                ans  = ans + topa[0];
                edges_count++;
            }
            
            
        }
        
        return ans;   
        
        
    }
};