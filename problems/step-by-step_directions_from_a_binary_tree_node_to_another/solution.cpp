// see prev solution also : 
// sol 2: Path finding + common prefix

// Build directions for both start and destination from the root.
// Say we get "LLRRL" and "LRR".
// Remove common prefix path.
// We remove "L", and now start direction is "LRRL", and destination - "RR"
// Replace all steps in the start direction to "U" and add destination direction.
// The result is "UUUU" + "RR".
// C++
// Here, we build path in the reverse order to avoid creating new strings.

class Solution{
public:

    bool find(TreeNode* root,int target, string &localPath){
        if(root == NULL) return false;
        if(root->val == target) return true;

        localPath.push_back('L'); // adding path
        bool isSeen = find(root->left, target, localPath);
        if(isSeen) return true; // already result is found, so stop the process. 
        localPath.pop_back(); // removing last path as result is not found. 
        
        localPath.push_back('R');
        isSeen = find(root->right, target, localPath);
        if(isSeen) return true;
        localPath.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s_p, d_p;
        find(root, startValue, s_p);
        find(root, destValue, d_p);
        reverse(s_p.begin(),s_p.end());
        reverse(d_p.begin(),d_p.end());
        // cout<<s_p<<" "<<d_p;
    
        while (!s_p.empty() && !d_p.empty() && s_p.back() == d_p.back()) {
            s_p.pop_back();
            d_p.pop_back();
        }
        return string(s_p.size(), 'U') + string(rbegin(d_p), rend(d_p));
    }
};