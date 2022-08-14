class Solution {
public:
    void rev(string &s,int i,int j){
        for(int k=0;k<=(j-i)/2;k++){
            swap(s[i+k],s[j-k]);
        }
    }
    string smallestNumber(string pattern) {

        string s="";
        
        for(int i=0;i<=pattern.length();i++){
            s+= '1'+i;
        }
        
        for(int i=0;i<pattern.length();i++){
            if(pattern[i]=='D'){
                int k=0,j=i;
                while(j<pattern.length() and pattern[j]=='D'){
                    k++;j++;
                    
                }
                rev(s,i,j);
                i=j;
            }
            
        }
        
        return s;
        
    }
};