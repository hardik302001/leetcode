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