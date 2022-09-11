class Solution {
public:
    int partitionString(string s) {
        int c = 1;
        map<int, int>m;
        int n = s.size();
        int p = -1;
        for(int  r = 0;r<n;r++){
            m[s[r]]++;
            if(m[s[r]]>1){
                c++;
                m.clear();
                m[s[r]]++;
            }
            
            p++;
        }
        
        return c;
        
        
    }
};