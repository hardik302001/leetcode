//OOH P silochan



class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ai,bi,ci;
        int res=0;
        while(a>0 || b>0 || c>0){
            ai=a%2;bi=b%2;ci=c%2;
            if(ci==1 && ai+bi==0)    //convert any of ai or bi to 1
                res++;
            else if(ci==0){        //ci = 0, then both ai and bi shud be 0..so flip = (ai==1) + (bi==1)
                if(ai){
                    res++;
                }
                if(bi){
                    res++;
                }
            }
            a/=2;b/=2;c/=2;
        }
        return res;
    }
};