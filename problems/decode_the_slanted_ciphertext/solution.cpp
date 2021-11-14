class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        int n = s.size();
        // cout<<n<<endl;
        int r = rows;
        int c = n/r;
        string ans;
        
        for(int i = 0;i<c;i++){
            int loop = min(r,c-i);
            // cout<<loop<<endl;
            int x = 0;
            int y = i;
            while(loop--){
                ans.push_back(s[x*c+y]);
                x++;
                y++;
            }
            
        }
        // cout<<ans<<endl;
        
        while(ans.size()>0){
            if(ans.back()==' ')
            ans.pop_back();
            else break;
        }

        
        return ans;
    }
};