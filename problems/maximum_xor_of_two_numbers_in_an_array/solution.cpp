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
    int findMaximumXOR(vector<int>& nums) {
        
        //build trie
        TrieNode* root = new TrieNode;          
        
        /* INSERT FUNCTION  */ 
        for(int &num:nums){
            insert(root , num);
        }
        
        /* Choosing all possible nums[j] and checking which gives maximum XOR with nums[i]  */
        int ans = 0;
        for(int &num : nums){
            int res = findMax(root, num);
            ans = max(ans, res);
        }
        
        clear(root);           // before returning always delete the root!
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
                cur = cur->child[index ? 0 : 1];  // benefitting way is Null, so we dont have any choice to choose the other way(the same value as in num, bcz we arent getting different value)
            }
        }
        return res;
    }
    
    
    
    void clear(TrieNode* root){
        for(int i=0;i<2;i++){
            if(root->child[i])   clear(root->child[i]);
        }
        delete root;
    }

    
};


/*
Time: O(32 * N)
Space: O(32 * N)
*/