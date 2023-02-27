// idea : NeetCode https://www.youtube.com/watch?v=UQ-1sBMV0v4


/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* dfs(int r , int c , vector<vector<int>>& grid , int n ){
        bool allSame = true;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[r][c]!= grid[r+i][c+j]){
                    allSame = false ;
                    break;
                }
            }
        }

        if(allSame) 
            return new Node(grid[r][c] , true , NULL , NULL, NULL , NULL);
        
        
        Node* root = new Node(0 , false);
        //                    /\ 0 bcz it can be any value, bcz it not a leaf 

        root->topLeft = dfs(r , c , grid , n/2);
        root->topRight = dfs(r , c+n/2 , grid , n/2);
        root->bottomLeft = dfs(r+n/2 , c, grid , n/2);
        root->bottomRight = dfs(r+n/2 , c+n/2 , grid , n/2);
        return root;
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return dfs(0 , 0 , grid , n);
    }
};