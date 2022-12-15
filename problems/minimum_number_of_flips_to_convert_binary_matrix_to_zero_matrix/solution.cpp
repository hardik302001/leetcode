// brute force , bfs

class Solution {
    #define matrix vector<vector<int>>
    int n, m;
    map<matrix, int> dis;
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    inline bool isValid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
    vector<matrix> get_neighbors(matrix& mat) {
        vector<matrix> ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                matrix mat2 = mat;
                mat2[i][j] = !mat[i][j];
                for(int dir = 0; dir < 4; dir++) {
                    int x = i + dx[dir], y = j + dy[dir];
                    if(isValid(x, y)) mat2[x][y] = !mat[x][y];
                }
                ans.push_back(mat2);
            }
        }
        return ans;
    }
    
    inline bool check(matrix& mat) {   // if it is a zero matrix or not
        bool ok = 1;
        for(auto& v : mat) {
            for(int& i : v) {
                ok &= !i;
            }
        }
        return ok;
    }
    
    int bfs(matrix mat) {
        queue<matrix> q;
        q.push(mat); dis[mat] = 0;
        
        while(q.size()) {
            matrix mat = q.front(); q.pop();
            int d = dis[mat];
            if(check(mat)) return d;
            auto v = get_neighbors(mat);
            for(auto& mat : v) {
                if(!dis.count(mat)) {
                    dis[mat] = d + 1;
                    q.push(mat);
                }
            }
        }
        
        return -1;
    }
    
public:
    int minFlips(vector<vector<int>>& mat) {
        n = mat.size(), m = mat[0].size();
        dis.clear();
        return bfs(mat);
    }
};