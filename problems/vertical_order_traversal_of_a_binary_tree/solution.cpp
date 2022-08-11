// https://leetcode.com/problems/binary-tree-right-side-view/

// also see: right view/left view
// top view
// bottom view

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int> > m;  // when iterate map, key is already the order of x-axis
        queue<pair<int, TreeNode*> > q; // for level traversal
        q.push(make_pair(0, root));  // root default x-axis is 0, horiontal dis = 0
        while(!q.empty()) {
            multiset<pair<int, int> > tmp;  // k: x-axis, v:val Already solved the case when the position is ths same   
            // multiset , bcz what if we have same value nodes [3,1,4,0,2,2] , or use vector and sort it
            
            int len=q.size();
            for(int i=0;i<len;++i) {
                auto p=q.front();q.pop();
                tmp.insert(make_pair(p.first, p.second->val));
                if (p.second->left) q.push(make_pair(p.first-1, p.second->left));
                if (p.second->right) q.push(make_pair(p.first+1, p.second->right));
            }

            for(auto p : tmp) 
            {
                m[p.first].push_back(p.second);
        
            }
            cout<<endl;
        }

        vector<vector<int> > res;
        for(auto kv : m) res.push_back(kv.second);
        return res;
    }
};   

// the time complexity will be o( n * log( x * y ) ),where n is the total number of nodes, x is width of the tree, y= height of the tree.
// and space complexity will be o(n + y) ==>n=Total number of nodes and y= height of the tree.

// -------------------------------------------------------------------------------------------------------.

// bottom view: update till end
// tc, sc: O(n)

/*
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans; 
        if(root == NULL) return ans; 
        map<int,int> mpp; 
        queue<pair<Node*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            Node* node = it.first; 
            int line = it.second; 
            mpp[line] = node->data; 
            
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
        return ans;  
    }
};
*/


// -----------------------------------------------------------------------------------------

// top view
// only update once, tc, sc : O(1)

/*
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans; 
        if(root == NULL) return ans; 
        map<int,int> mpp; 
        queue<pair<Node*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            Node* node = it.first; 
            int line = it.second; 
            if(mpp.find(line) == mpp.end()) mpp[line] = node->data; 
            
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
        return ans; 
    }

};
*/