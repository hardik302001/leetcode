class Solution {
public:
    bool subseq(string x, string s){
        int m = x.size();
        int n = s.size();
        int i = 0;
        int j = 0;
        while(i<m and j<n){
            if(x[i]==s[j]){
                i++;
            }
            j++;
        }
        
        return i==m;
        
    }
    string findLongestWord(string s, vector<string>& d) {
        int ma = 0;
        string ans;
        for(auto x: d){
            if(subseq(x, s)){
                if( (int)x.size()>ma){
                    ans = x;
                    ma = (int)x.size();
                }else if( (int)x.size()==ma and x<ans){
                    ans = x;
                }
            }
        }
        
        return ans;
    }
};