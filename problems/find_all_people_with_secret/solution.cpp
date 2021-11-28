// Time: O(MlogM + N) where `M` is the length of `meetings`
// Space: O(N)

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
         
            bool connected(int a, int b) {
                return find(a) == find(b);
            }
            
         
    };
    
    static bool comp(vector<int>&a, vector<int>&b){
        if (a[2]<b[2]){
            return true;
        }
        return false;
    }
    
    
    vector<int> findAllPeople(int n, vector<vector<int>>& A, int firstPerson) {
        sort(begin(A), end(A),[](auto &a, auto &b) { return a[2] < b[2]; }); // Sort the meetings in ascending order of meeting time
        int i = 0;
        int M = A.size();
        UnionFind uf(n);
        uf.Union(0, firstPerson); // Connect person 0 and the first person
        vector<int> ppl;
        while (i < M) {
            ppl.clear();
            int time = A[i][2];
            while (i < M && A[i][2] == time) { // For all the meetings happending at the same time
                uf.Union(A[i][0], A[i][1]); // Connect the two persons
                ppl.push_back(A[i][0]); // Add both persons into the pool
                ppl.push_back(A[i][1]);
                ++i;
            }
            for (int person : ppl) { // For each person in the pool, check if it's connected with person 0.
                if (!uf.connected(0, person)) uf.parent[person] = -1; // If not, this person doesn't have secret, reset it.
            }
        }
        vector<int> ans;
        for (int j = 0; j < n; ++j) {
            if (uf.connected(0, j)) ans.push_back(j); // Push all the persons who are connected to person 0 into answer array
        }
        return ans;
    }
};