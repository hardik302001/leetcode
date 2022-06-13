class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>ss(deadends.begin() , deadends.end());
        if (ss.count("0000")) {
            return -1;
        }
        queue<string>q;
        q.push("0000");
        
        int ans = 0;
        while(q.size()){
            int sz = q.size();
            while(sz--){
                auto s = q.front();
                q.pop();
                
                if(s==target){
                    return ans;
                }
                
                for(int i = 0;i<4;i++){
                    string temp = s;
                    char next = (((temp[i]-'0')+1)%10+'0');
                    char prev = (((temp[i]-'0')-1+10)%10+'0');
                    temp[i] = next;
                    if(temp!=s and ss.count(temp)==0){
                        q.push(temp);
                        ss.insert(temp);
                    }
                    
                    temp[i] = prev;
                    if(temp!=s and ss.count(temp)==0){
                        q.push(temp);
                        ss.insert(temp);
                    }
                }
                
            }
            ans++;
        }
        
        
        
        return -1;
        
        
        
    }
};