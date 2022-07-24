// maximum number of nodes between left most and right node
// level order

// This new approach inserts only the non-NULL nodes in the queue along with their indices in the tree. The index of the left and right child nodes are 2*parent_index + 1 and 2*parent_index + 2 respectively. Thus, the space and time required to process the NULL nodes earlier being pushed into the deque is eliminated.


// see striver video for idea: https://www.youtube.com/watch?v=ZbybYvcVLks&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=29
class Solution {
public:
	int widthOfBinaryTree(TreeNode* root) {
		if(!root)   return 0;
		int ans=1;
		queue<pair<TreeNode*,int>> Q;
		Q.push({root,0});
		while(!Q.empty())
		{
			int n = Q.size(),st,end;
			int mini = Q.front().second;   // very important to keep track of prev row minimum
			for(int i=0;i<n;i++)
			{
				TreeNode *node = Q.front().first;
				int ind = Q.front().second-mini; // subtracted to prevent integer overflow
                  // you can also avoid it, bcz low constraints, but what if you have a long skew tree, evertine you do *2, it will tle
                  // everytime we start from 0
				Q.pop();
				if(i==0)           st = ind;
				if(i==n-1)         end = ind;
				if(node->left)     Q.push({node->left, (long)2*ind+1});
				if(node->right)    Q.push({node->right, (long)2*ind+2});
			}
			ans = max(ans, end-st+1);
		}
		return ans;
	}
};


//-------------------------------------------------------------
// below code, here we arent updating our indexing
/*
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
    
     if(!root) return 0;
        
        //similar to level order
        queue<pair<TreeNode *, unsigned long long int>> q;
        int maxwidth =0;
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            
            
            unsigned long long int left_index = q.front().second, right_index = 0;
            unsigned long long int sz = q.size();
            
            
            for(unsigned long long int i=0; i<sz; i++){
                
                pair<TreeNode *, unsigned long long int> p = q.front();
                q.pop();
                TreeNode *temp = p.first;
                right_index = p.second;              // here , we are directly doing *2 for cur_node , may lead to tle
                
                if(temp->left)
                    q.push(make_pair(temp->left, 2*right_index + 1));
                if(temp->right)
                    q.push(make_pair(temp->right, 2*right_index + 2));
                
            }
            
            maxwidth = max(maxwidth, int(right_index - left_index + 1));
        }
        
        return maxwidth;
        
    }
};
*/