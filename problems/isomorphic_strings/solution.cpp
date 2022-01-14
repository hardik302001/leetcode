class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        int m = t.size();
        unordered_set<char> ss;
        unordered_map<char, char>mp;
        if(n==m){
            for(int i = 0;i<n;i++){
                if(mp.count(s[i])==0){
                    if(ss.count(t[i])==0){
                        mp[s[i]] = t[i];
                        ss.insert(t[i]);
                    }else{
                        return false;
                    } 
                }else{
                    if(mp[s[i]]!=t[i]){
                        return false;
                    }
                }
            }
            
            return true;
        }
        return false;
        
        
    }
};