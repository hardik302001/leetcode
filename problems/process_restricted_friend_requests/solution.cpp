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
                return parent[x] = find(parent[x]);   //path comp
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

    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        UnionFind uf(n);
        vector<bool> ans;
        
        //CONCEPT:- My enemy's enemy is my friend
        for(int i=0; i<requests.size(); i++){
            UnionFind t = uf;  //copy the previous dsu to check that the current request will be accepted or not
            t.Union(requests[i][0],requests[i][1]);
            bool flag = false;
            
            for(auto &it: restrictions){
                if(t.find(it[0]) == t.find(it[1])){ //check that would there be any restriction which we had 
                    flag = true;                    //accepted but not supposed to be accepted
                    break;
                }
            }
            
            if(flag==false){
                uf.Union(requests[i][0],requests[i][1]); //request approved -> true/ change in main dsu
                ans.push_back(true);
            }
            else{
                ans.push_back(false); //request rejected -> false/ no need to change main dsu
            }
        }
        
        return ans;
        
    }

}; 