// https://leetcode.com/problems/maximum-xor-with-an-element-from-array/discuss/988142/C%2B%2B-or-Trie-based-Solution-with-Explanation
// also see striver video

// similar to : https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

// striver video!


class TrieNode{
public:
    TrieNode* child[2];
    TrieNode(){
        for(int i = 0;i<2;i++){
            child[i] = NULL;
        }
    }
};


class Solution {
public:
      vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        //build trie
        TrieNode* root = new TrieNode;          
        
        /* INSERT FUNCTION  */ 
        vector<vector<int>> q;
        for (int i = 0; i < queries.size(); i++) {
            auto v = queries[i];
            q.push_back({v[1], v[0], i});
        }
        sort(q.begin(), q.end());
        sort(nums.begin(), nums.end());
        
        int j = 0;
        vector<int> ans(queries.size(), -1);
        
          
         // now we need not reset j everytime!
        for (const auto& p : q) {
            int x = p[1];
            int threshold = p[0];
            while (j < nums.size() && nums[j] <= threshold) {
                insert(root , nums[j]);
                j++;
            }
            if(j){
                int temp = findMax(root, x);
                ans[p[2]] = temp;
            }
        }
          
        // clear(root);
        return ans;
        
    }
    
    void insert(TrieNode* root, int num){
        TrieNode* cur = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (cur->child[bit] == nullptr) cur->child[bit] = new TrieNode;
            cur = cur->child[bit];
        }
    }
    
    int findMax(TrieNode* cur, int num) {
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int index = ((num >> i) & 1) ? 0 : 1;      // bcz we want different bits, bcz then only we will get XOR  as 1
            if (cur->child[index]!= NULL) {
                res  = res | (1<<i);
                cur = cur->child[index];   //considered the benefitting way
            } else {
                cur = cur->child[index ? 0 : 1];  // benefitting way is Null, so we dont have any choice to choose the other way
            }
        }
        return res;
    }
    
    
    
    // void clear(TrieNode* root){
    //     for(int i=0;i<2;i++){
    //         if(root->child[i])   clear(root->child[i]);
    //     }
    //     delete root;
    // }

    
};


