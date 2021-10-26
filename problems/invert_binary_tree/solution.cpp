//SEE PREV SOLNS FOR DFS RECURSIVE SOLUTION

// Look for bfs solution always in tree questions!
//because of large skewed tree case, it is a linkedlist and traversing deep and deep in dfs  recursive way will lead to memory overflow!

//    If you draw the 3 or 4 level, just to make sure, binary tree and invert it on a paper, you will easily see that all have to be done is to swap kids for each node. This can be done many ways: recursion or using queue to store nodes of one level. Recursion is not good way to go due to performance overhead and risk to run it against huge tree. With standard queue solution looks simple robust and runs faster.



// exactly sme logic as recursive solution, swap and move on!
class Solution {
public:

    TreeNode* invertTree(TreeNode* root) {

        if(nullptr == root) return root;

        queue<TreeNode*> myQueue;   // our queue to do BFS
        myQueue.push(root);         // push very first item - root

        while(!myQueue.empty()){    // run until there are nodes in the queue 

            TreeNode *node = myQueue.front();  // get element from queue
            myQueue.pop();                     // remove element from queue
            // invert left and right pointers      
            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;
            
            
            if(node->left != nullptr){         // add left kid to the queue if it exists
                myQueue.push(node->left);
            }

            if(node->right != nullptr){        // add right kid 
                myQueue.push(node->right);
            }



        }

        return root;
    }
};