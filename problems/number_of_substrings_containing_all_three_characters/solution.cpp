class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0;
        int ans = 0;
        int n = s.size();
        int a = 0, b = 0, c = 0;
        for (int r = 0;r<n;r++){ 
            if(s[r]=='a')a++;
            else if(s[r]=='b')b++;
            else c++;

            
            while(a>0 and b>0 and c>0){
                ans = ans + (n-r);     // noice!
                if(s[l]=='a')a--; 
                else if(s[l]=='b')b--;
                else c--;
                l++;
            }      
    
        }
        return ans;
    }
};