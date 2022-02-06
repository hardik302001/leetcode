class Solution {
public:
    int minCostSetTime(int st, int mc, int pc, int tar) {
        int ans = INT_MAX;
        for(int i = 0;i<100;i++){
            for(int j = 0;j<100;j++){
                int t = 60*i + j;
                if(t==tar){       // All combination of minutes and seconds!0
                    ans = min(ans, check(to_string(i), to_string(j), st , mc , pc));
                }
            }
        }
        
        return ans;
    }
    
    int check(string x , string y , int st , int mc , int pc){
        if(y.size()==1){
            y = '0' + y;
        }
        if(x.size()==1){
            x = '0' + x;
        }
        string p = x+ y;
        // cout<<p<<endl;
        int n = p.size();
        int res = 0;
        bool startingzero = 1;
        for(int i = 0;i<n;i++){
            if(startingzero and (p[i]-'0'==0)){
                continue;
            }
            else{
                startingzero = 0;
                if(p[i]-'0'==st){
                    res += pc;
                }
                else{
                    res += mc;
                    res += pc;
                }             
                st = p[i] - '0';
            }

        }
        // cout<<res<<endl;
        return res;
        
    }
};