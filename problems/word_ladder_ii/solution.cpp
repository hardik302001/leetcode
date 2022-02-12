class Solution {
public:
    vector<vector<string>> findLadders(string begin, string end, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(), wordList.end());
        vector<vector<string>>ans;
        vector<string>vis;
        queue<vector<string>>q;
        q.push({begin});
        
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                vector<string>topa = q.front();
                q.pop();
                string cur = topa.back();
                if(cur==end){
                    ans.push_back(topa);
                }
                
                for(int i = 0;i<cur.size();i++){
                    string temp = cur;
                    for(char x = 'a';x<='z';x++){
                        temp[i] = x;
                        if(temp==cur){
                            continue;
                        }
                        if(s.find(temp)!=s.end()){
                            auto new_path = topa;
                            new_path.push_back(temp);
                            q.push(new_path); 
                            vis.push_back(temp);
                        }
                    }
                }
            }
            
            for(auto it: vis){
                s.erase(it);
            }
            vis.clear();
        }
        
        
        return ans;
        
    }
};