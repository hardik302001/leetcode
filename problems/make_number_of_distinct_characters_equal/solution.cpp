class Solution {
public:
    bool isItPossible(string word1, string word2) {
        map<char, int>m1;
        map<char, int>m2;
        for(auto x: word1) m1[x]++;
        for(auto y: word2) m2[y]++;
        if(abs((int)m1.size()-(int)m2.size())>2) return false;
        
        for(auto x : m1){
            for(auto y : m2){
                if(m1[x.first]>0 and m2[y.first]>0){ // bcz after some perations, we would have some keys with 0 value, so we cant use those keys, bcz they dont actually exist in map
                    m1[x.first]-=1;
                    m1[y.first]+=1;
                    m2[y.first]-=1;
                    m2[x.first]+=1;
                    int c1 = 0;
                    int c2 = 0;
                    for(auto z: m1) if(m1[z.first]>=1) c1++;
                    for(auto z: m2) if(m2[z.first]>=1) c2++;
                    if(c1==c2) {
                        return true;
                    }
                    m1[x.first]+=1;
                    m1[y.first]-=1;
                    m2[y.first]+=1;
                    m2[x.first]-=1;
                }
            }
        }
        
        return false;
    }
};