//  can aslo be done using BS + PQ
// see that method also


class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res;
        
        vector<pair<int,int>> vp;
        
        for(int i=0;i<mat.size();i++){
            int count = 0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j] == 1)
                    ++count;
                        
            }
            vp.push_back(make_pair(count,i));
        }
        sort(vp.begin(),vp.end());
         for(int i=0;i<k;i++){
              res.push_back(vp[i].second);  
         }
        
        return res;
        
    }
};