class Solution {
public:
    string maskPII(string S, string ans="", string nums="") {
        auto pos=S.find('@');
        if (pos==string::npos){
            for (auto c: S) if (isdigit(c))
                nums.push_back(c);
            int N=(int)nums.size();
            ans=N==13 ? "+***-" : N==12 ? "+**-" : N==11 ? "+*-" : "";
            ans.append("***-***-"+nums.substr(N-4));
        } else {
            ans=string(1,S[0])+"*****"+S.substr(pos-1);
            transform(ans.begin(),ans.end(),ans.begin(),::tolower);
        }
        return ans;
    }
};
