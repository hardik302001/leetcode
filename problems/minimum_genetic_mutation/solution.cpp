class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if(start==end){
            return 0;
        }
        
        unordered_set<string>s(bank.begin(), bank.end());
        queue<string>q;
        q.push(start);
        int result = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string cur = q.front();
                q.pop();
                
                if(cur==end){
                    return result;
                }
                

                for(int i = 0;i<8;i++){
                    string temp = cur;
                    for(char x = 'A';x<='Z';x++){
                        temp[i] = x;
                        if (temp==cur){
                            continue;
                        }
                        
                        if(s.find(temp)!= s.end()){
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
             
                
            }
            result++;
        }
        
        
        
        
        return -1;
        
        
    }
};