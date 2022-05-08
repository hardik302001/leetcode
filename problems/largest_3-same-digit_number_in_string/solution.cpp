class Solution {
public:
    string largestGoodInteger(string num) {
        int ans=-1;
        for(int i=0;i+2<num.size();i++){
            if(num[i]==num[i+1] && num[i]==num[i+2]) ans= max(ans,num[i]-'0');
        }
        return ans!=-1? string(3,ans+'0') : "";
    }
};