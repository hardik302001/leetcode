class Solution {
public:
   
    // CYCLE SORT : CODENCODE
    int minSwaps(vector<int>arr)
    {
        int n = arr.size();
        // Create an array of
        // pairs where first
        // element is array element
        // and second element
        // is position of first element
        pair<int, int> arrPos[n];
        for (int i = 0; i < n; i++)
        {
            arrPos[i].first = arr[i];
            arrPos[i].second = i;
        }

        // Sort the array by array
        // element values to
        // get right position of
        // every element as second
        // element of pair.
        sort(arrPos, arrPos + n);
        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            // already swapped and corrected or
            // already present at correct pos
            if (vis[i] || arrPos[i].second == i)
                continue;

            // find out the number of  node in
            // this cycle and add in ans
            int cycle_size = 0;
            int j = i;
            while (!vis[j])
            {
                vis[j] = 1;
                // move to next node
                j = arrPos[j].second;
                cycle_size++;
            }

            // Update answer by adding current cycle.
            if (cycle_size > 0)    ans += (cycle_size - 1);
            
        }

     
        return ans;
    }
 
        
        
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> t;
            while(n--){
                TreeNode* node = q.front();
                t.push_back(node->val);
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
            ans += minSwaps(t);
        }
        return ans;
    }
};