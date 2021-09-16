//see prev code also




class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = n-1;
        int up = 0;
        int down = m-1;
        
        while(ans.size()<n*m){
            for(int i = left;i<=right and ans.size()<n*m;i++){
                ans.push_back(matrix[up][i]);
            }
            for(auto it:ans){
                cout<<it<<' ';
                
            }
            cout<<'\n';
            for(int i = up+1;i<=down and ans.size()<n*m;i++){
                ans.push_back(matrix[i][right]);
            }
            for(auto it:ans){
                cout<<it<<' ';
                
            }
            cout<<'\n';
            for(int i = right-1;i>=left and ans.size()<n*m;i--){
                ans.push_back(matrix[down][i]);
            }
            for(auto it:ans){
                cout<<it<<' ';
                
            }
            cout<<'\n';
            for(int i = down-1;i>=up+1 and ans.size()<n*m;i--){
                ans.push_back(matrix[i][left]);
            }
            for(auto it:ans){
                cout<<it<<' ';
                
            }
            cout<<'\n';
            left++;
            right--;
            up++;
            down--;
            
        }
        
        return ans;
    }
};