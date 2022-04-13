// use same code for spiral matrix and spiral matrix 2

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;  
        
        if (matrix.size() <= 0 || matrix[0].size() <= 0)
            return ans;
            
        int m = matrix.size(), n = matrix[0].size();
        int x0 = 0, x1 = m - 1; // vertical
        int y0 = 0, y1 = n - 1; // horizon
        
        while(x0 <= x1 && y0 <= y1) {    
            // travel right side
            for (int j = y0; j <= y1; ++j)
                ans.push_back(matrix[x0][j]);
            x0++;
            
            // travel down side
            for (int i = x0; i <= x1; ++i)
                ans.push_back(matrix[i][y1]);
            y1--;
            
            if (x0 > x1) break;
            // travel left side
            for (int j = y1; j >= y0; --j) 
                ans.push_back(matrix[x1][j]);
            x1--;
            
            if (y0 > y1) break;
            // travel up side
            for (int i = x1; i >= x0; --i)
                ans.push_back(matrix[i][y0]);
            y0++;
        }
        
    
        
        return ans;
    }
};


/*


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
*/