//this is my first approach, but it is not optimised!!
//see previous approach, that is better and optimised

class Solution {
public:
     unordered_map<int, int> freqMap;
    void initFreqMap(TreeNode* root) {
        if (root == nullptr){
            return;
        }
        auto it = freqMap.find(root->val);
        if (it != freqMap.end()){
            it->second++;
        }
        else{
            freqMap.insert(pair( root->val, 1));
        }
        initFreqMap(root->left);
        initFreqMap(root->right);       
    }
    
    vector<int> findMode(TreeNode* root) {
        
       
        initFreqMap(root);
        
        vector<int> res;
        int max = INT_MIN;
        for (pair element : freqMap)
        {
	        if (element.second > max) {
                max = element.second;
            }
        }
        
        for (pair element : freqMap)
        {
	        if (element.second == max) {
                res.push_back(element.first);
            }
        }
        return res;
    }
};