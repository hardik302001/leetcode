class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long a = count(pattern[0] + text, pattern);
        long long b = count(text + pattern[1], pattern);
        
        return max(a , b);
    }
    
    long long  count(string a, string b)
    {
        long long x = 0;
        long long y = 0;
        for(int i = 0;i<a.size();i++){
            if(a[i]==b[0]){
                x+=1;  
            }
            else if(a[i]==b[1]){
                y+=x;
            }
            
        }
        
        
        if(b[0]==b[1]){
            return x*(x-1)/2;
        }
        return y;
    }
};