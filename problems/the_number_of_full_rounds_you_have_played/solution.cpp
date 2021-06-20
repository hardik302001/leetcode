class Solution {
public:
    int numberOfRounds(string s, string f) {
        int sh=stoi(s.substr(0,2)),sm=stoi(s.substr(3,2));
        int fh=stoi(f.substr(0,2)),fm=stoi(f.substr(3,2));
        
        if(sm%15){
            int temp=sm/15;
            if(temp==3){
                sh++;
                sm=0;
            }
            else{
                sm=(1+temp)*15;
            }
        }
        if(fm%15){
            int temp=fm/15;
            fm=temp*15;
        }
        if(sh==fh && sm<=fm){
            return (fm-sm)/15;
        }
        else if(sh<fh){
            int d=fh-sh;
            int m=60*d+fm-sm;
            return m/15;
        }
        else{
            int d=sh-fh;
            int m=60*(24-d)+fm-sm;
            return m/15;
        }
        
    }
};