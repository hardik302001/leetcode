
class Solution {
public:

static bool comp(pair<char,int>&a, pair<char,int>&b)
{
    if(a.first < b.first){
        
        return true;
    }
    
    if(a.first == b.first){
        
        if(a.second > b.second){
            
            return true;
        }
    }
   return false;
}
string frequencySort(string s) {
    
    map<char,int> m;
    
    for(int i=0; i<s.size( ); i++){
        
        m[s[i]]++;
    }
     sort(s.begin(), s.end(), [&](char a, int b) { 
            return m[a] > m[b] || (m[a] == m[b] && a < b); 
        });
   return s;
    
    
}
};