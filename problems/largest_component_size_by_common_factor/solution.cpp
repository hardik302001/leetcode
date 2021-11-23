class Solution {
public:
    class UnionFind {
        public:  
            vector<int> parent;
            int count = 0;
            UnionFind(int n){                  //constructor
                count = n;
                for(int i = 0;i<(n+1);i++){    //path compression
                    parent.push_back(i);
                }
            }

            int find(int x){
                if(parent[x]==x) return x;
                return parent[x] =  find(parent[x]);
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
    
     

    int largestComponentSize(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end()) + 1;
        UnionFind uf(n); //create DSU struct with nodes 0, 1, 2, ... max element of the vector
	    for(auto i: nums){
		    for(int j = 2;j*j<=i;j++){ //factorize each number
			    if(i%j == 0){
				    uf.Union(j, i);
				    uf.Union(i/j, i);
			    }
		    }
	    }
        
                vector<int>count(n);
        for(int i =0;i<nums.size();i++){
            count[uf.find(nums[i])]++;
        }
        
        return *max_element(count.begin(),count.end());
    }
};