/*
class Solution {
public:
    // c++  code
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        string ans;
        
        for (int a=1; a<=3; a++)
        for (int b=1; b<=3; b++)
        for (int c=1; c<=3; c++)
        for (int d=1; d<=3; d++)
            if (a+b+c+d == s.length()) {
                int A = stoi(s.substr(0, a));
                int B = stoi(s.substr(a, b));
                int C = stoi(s.substr(a+b, c));
                int D = stoi(s.substr(a+b+c, d));
                if (A<=255 && B<=255 && C<=255 && D<=255){
                    ans=to_string(A)+"."+to_string(B)+"."+to_string(C)+"."+to_string(D);
                    if(ans.length()==s.length()+3){   //bcz suppose we considered "01", but it is actually "1"..so we are checking that thing using length
                        ret.push_back(ans);
                    }
                }
            }    
        
        return ret;
    }
};

*/

// backtracking

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string ip;
        dfs(s,0,0,ip,result); //paras:string s,start index of s,step(from0-3),intermediate ip,final result
        return result;
    }
    void dfs(string s,int start,int step,string ip,vector<string>& result){
        if(start==s.size()&&step==4){
            ip.erase(ip.end()-1); //remove the last '.' from the last decimal number
            result.push_back(ip);
            return;
        }
        
        if(s.size()-start>(4-step)*3) return;   // more chars are left than required
        if(s.size()-start<(4-step)) return;    // less chars are required than required
        
        int num=0;
        for(int i=start;i<min(start+3, int(s.size()));i++){
            num=num*10+(s[i]-'0');
            if(num<=255){
                ip+=s[i];  // we are updating ip at every step
                dfs(s,i+1,step+1,ip+'.',result);
            }
            if(num==0) break;            // very important
        }
    }
};