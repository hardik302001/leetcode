// time comp: O(n)
//space =   O(height)


// ARITHEMATIC OPERATIONS
class Solution {
public:
    
    void recur(TreeNode* src, int temp, int &sum){
        temp = temp*10 + src->val;
        if(src->left ==NULL and src->right==NULL){
            sum = sum + temp;
            return ;
        }
        if(src->left)   recur(src->left, temp, sum );
        if(src->right) recur(src->right , temp, sum );
    }
    
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        recur(root, 0, sum);
        return sum;
    }
};



// STRING OPERATIONS!
/*

class Solution {
public:
    vector<int>nums;
    void recur(TreeNode* src, string s){
        if(src->left ==NULL and src->right==NULL){
            nums.push_back(stoi(s + to_string(src->val)));
            return ;
        }
        if(src->left)   recur(src->left, s + to_string(src->val));
        if(src->right) recur(src->right , s + to_string(src->val));
    }
    
    int sumNumbers(TreeNode* root) {
        recur(root, "0");
        int s = 0;
        for(int i = 0;i<nums.size();i++){
            s = s+ nums[i];
        }
        return s;
    }
};

*/