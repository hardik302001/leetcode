/*
n = 1, 1
n = 2, 11
n = 3, 21
n = 4, 1211


*/

class Solution{
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        
        string prev = "1";
        string cur = "";
        
        for(int i = 2;i<=n;i++){
            int count = 1;
            for(int j = 0;j<prev.size()-1;j++){
                if(prev[j]==prev[j+1]) count++;
                else {                  
                    cur+=( to_string(count) + prev[j]);
                    count = 1;
                }
            }   
            // bcz last index will be left, so we need to consider it explicitly
            cur+=( to_string(count) + prev[prev.size()-1]);
            
            prev = cur;
            cur = "";
        }
        
        return prev;
            
        
    }
};