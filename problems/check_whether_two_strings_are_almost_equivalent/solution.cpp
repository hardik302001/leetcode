class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
     vector<int>a(26,0),b(26,0);
        
        for(auto i : word1){
            a[i-'a']++;
        }
        
        for(auto i : word2){
            b[i-'a']++;
            
        }
        bool f = true;
        for(int i = 0;i<26;i++){
            if(abs(a[i]-b[i])>3){
                f = false;
            }
        }
        
        return f;
        
        
    }
};