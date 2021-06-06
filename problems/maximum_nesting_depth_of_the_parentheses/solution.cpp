class Solution {
public:
    int maxDepth(string s) {
        int c = 0;
        int ma = 0;
        for(auto it : s){
            
            if(it=='('){
                cout<<it;
                c++;
                ma = max(c,ma);
            }
            else if(it==')'){
                c--;
            }
        }
        return ma;
    }
};