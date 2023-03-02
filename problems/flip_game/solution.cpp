class Solution {
public:
    vector<string>ans;
    void backtrack(int i ,string &temp,  string &cur , int f){
        int n = cur.size();
        if(i==n){
            if(f) ans.push_back(temp);
            return;            
        }
        if(i+1<n){
            if(cur[i]=='+' and cur[i+1]=='+' and f==0){
                temp+= '-';
                temp+= '-';
                backtrack(i+2,  temp , cur , f|1);
                temp.pop_back();
                temp.pop_back();
            }
        }
        temp.push_back(cur[i]);
        backtrack(i+1 , temp , cur , f);
        temp.pop_back();

    }
    vector<string> generatePossibleNextMoves(string cur) {
        string temp;
        backtrack(0 , temp, cur , 0);
        return ans;
    }
};