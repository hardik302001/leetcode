class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        map<char , int>m1;
        map<char, int>m2;
        for(auto x: s1)m1[x]++;
        for(auto x: s2)m2[x]++;
        
        for(char i = 'a';i<='z';i++){
            if(m1[i]!=m2[i]) return false;
        }
        // now freq is equal
        int c = 0;
        int n = s1.size();
        for(int i = 0;i<n;i++){
            if(s1[i]!=s2[i]) c++;
        }
        
        return (c==0 or c==2);
        
    }
};
