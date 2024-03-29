// DFS SOLUTION IS MUCH BETTER







/*
Observation
When there are multiple indices that overlap each other eg: [1,2] and [2,3] we can always get the characters at those indices (1,2,3) at any of the indice we like by swapping in some permutation.
These overlapped indices form our "connected graph or connected components" and these belong to one group.
eg: [2,3],[4,5],[3,6],[2,7] for a string of length 8 we have the following groups:

0
1
2,3,6,7
4,5
We use this observation to build our solution.

Solution
All we need to do is get all those groups of indices that can be swapped with each other and sort the string formed by those indices since they can always be replaced/swapped by any other charater in those indices as noted above.
Repeat this for all the groups and you get your sorted string.
*/


// DSU
class UnionFind {
    public:  
        vector<int> parent;
        int count;
	    vector<int>size;
        UnionFind(int n){                      //constructor
            count = n;
            parent = vector<int>(n,-1);
	        size = vector<int>(n , 1);
        }

        int find(int x){                       // O(logn)
            if(parent[x]==-1) return x;
            return parent[x] = find(parent[x]);        // path compression   
        }

        bool Union(int x,int y){               // O(logn)
            int X = find(x);
            int Y = find(y);

            if(X==Y) return true;              // cycle found     

	        if (size[X] < size[Y])
            	swap(X, Y);
            
            parent[Y] = X;
            size[X] += size[Y];          
	   
            count--;
	        return false;
            
        }

        int getCount(){
            return count;
        }
         
        bool connected(int a, int b) {
            return find(a) == find(b);
        }     
    
        vector<int> pari(){return parent;}
         
};
class Solution {
public:    
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {
        int n = s.size();
        UnionFind uf(n);
        
        for(vector<int> &v:pairs){
            uf.Union(v[0],v[1]);
        }
        
        
        vector<int>parent = uf.pari();

        
        unordered_map< int, vector<char> > m1;
        unordered_map< int, vector<int > >m2;
        for(int i =0 ;i<n;i++){
            if(parent[i]==-1){m1[i].push_back(s[i]);
                              m2[i].push_back(i);}
            else{m1[uf.find(i)].push_back(s[i]);
                 m2[uf.find(i)].push_back(i);}
        }
        vector<char>ans(n);
    
        
        for(auto i: m2){
            sort(i.second.begin(),i.second.end());
            sort(m1[i.first].begin(),m1[i.first].end());

            vector<char> sorted = m1[i.first];
            for(int j = 0;j<i.second.size();j++){
                ans[i.second[j]] = sorted[j];
            }
        }
        
        
        string res;
        for(auto i:ans)res.push_back(i);
        

        return res;
    }
};



// DFS

/*
class Solution {
public:
    vector<int> indices;                                                 //Stores indices of same group.
    vector<bool> visited;
    vector<vector<int>> adjList;
    string indiceString;                                                 //Stores  string formed by indices in the same group.
    void dfs(string &s,int n)            //we can work on same string thats why we are considering &s, else evrytime we run dfs it will make a new copy of string,string takes O(n) whiel passing, so better be pass address of string(taht takes O(1) time)
        
        //DFS to get all indices in same group.
    {
        visited[n]=true;
        indices.push_back(n);
        indiceString+=s[n];
        for(int &i:adjList[n])
            if(!visited[i])
               dfs(s,i);
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {
        adjList.resize(s.length());
        visited.resize(s.length(),false);
        for(vector<int> &v:pairs)                         //Create adjacency list using the indice pairs
            adjList[v[0]].push_back(v[1]),adjList[v[1]].push_back(v[0]);
        
        
        for(int i=0;i<s.length();i++)
            if(!visited[i])
            {
                indiceString="";                              //Clear string formed by one group of indices before finding next group.
                indices.clear();                             //Clear indices vector before finding another group.
                dfs(s,i);
                sort(indiceString.begin(),indiceString.end());                    //Sort the characters in the same group.
                sort(indices.begin(),indices.end());                                  //Sort the indices in the same group.            
                for(int i=0;i<indices.size();i++)          //Replace all the indices in the same group with the sorted characters.
                    s[indices[i]]=indiceString[i];
            }
        return s;
    }
};

*/