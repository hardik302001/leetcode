//ULTIMATE GOOD PROBLEM

//DSU
/*
We can remove only one node!
There are three cases for the tree structure to be invalid.
1) A node having two parents; lets call it special node(having that imposter edge)
   including corner case: e.g. [[1,2],[1,3],[2,3]]
2) A cycle exists , but no candidates     [[1,2],[2,3],[3,4],[4,1],[1,5]]
3) A cycle exists, and canidates exist(special node)   [[2,1],[3,1],[4,2],[1,4]]

Either cycle exists or special node occurs(with or without cycle)   //ples dont get confused by this line, maybe just ignore it



Process:
1) Check whether there is a node having two parents.      case 1 
    If so,  store them as candidates A and B.  (either both can occurs or none of them)
    candA occurs before candB
    
2)  Then we need to look for cycles
     if no candidates then                                  case 2


    if candidates exist                                     case 3
    


3) Then we make unions of all nodes except our special node.
SO, first of all, If at any point we find a cycle, then our first priority is to look for candA(because it is potential imposter and it takes part in union process)             case 3

TRY TO SIMULATE PROCESS IN [[2,1],[3,1],[4,2],[1,4]]  for more info why candA will go first..
If candA exists, it means that it is the one that takes part in cycle formation and 2 parent situatin, so we remove it!

If candA doesnot exist (neither candA nor candB), then it means current edge is imposter,
that leads to cycle formation, same as we did in REDUNDANT CONNECTION I (https://leetcode.com/problems/redundant-connection/)
return current edge                         case 2

Now , we have seen all cases of possible cycle formation. It means we have made all unions of nodes except our special edge and  we did not found any cycles.
So it means it the situation of 2 parent that leads to invalid tree. But this time we have candA and candB (both) as potential imposters....which one to choose...
Either of them can be removed and we will get a valid tree.
TRY TO SIMULATE IN [[2,1],[3,1],[4,3],[1,4]] for more info why candB will go.    PS(it is a different test case but similar to one mentioned above)..

But according to ques, we want one that occurs last, so its candB!             case 1

We covered all cases..So, hope it was clear!
Just try to simulate the testcases given in beginning with the following code. 

*/


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
                cout<<X<<" "<<Y<<endl;
                if(X==Y) return true;   //cycle found

                parent[Y]=X;         //A ->B
                count--;
                return false;
            }
            

            int getCount(){
                return count;
            }
    };
    
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = size(edges);
        vector<int> parent(n+1, 0), candA, candB;
        // step 1, check whether there is a node with two parents
        //candA occured before candB
        
        for (auto &edge:edges) {
            if (parent[edge[1]] == 0)
                parent[edge[1]] = edge[0]; 
            else {
                candA = {parent[edge[1]], edge[1]};
                candB = edge;
                edge[1] = 0;     //the edge(canB) destination is marked as 0 to identify it uniquely , the node with 2 parents..
                //the edge candA will still take part in union process..
                
            }
        } 
        
        
        
        UnionFind uf(n);
        
        
        for(auto& edge : edges) {
            if (edge[1] == 0) continue;    //wait for now, dont make connections from special node now
            int u = edge[0], v = edge[1];
           
            if(uf.Union(u,v)){
                //returned true, means cycle exists
                if(candA.size()){
                    cout<<"A";
                    return candA;
                }
                else{
                    cout<<"edge";
                    return edge;
                }
                
            }
        }
        
        cout<<"B";
        return candB;
    
    }
        
};