//BFS

class Solution {
public:   
    vector< string > board = vector<string>{"abcde", "fghij","klmno","pqrst","uvwxy","z****"}; 
    unordered_map<char, pair<int,int>> mp;
    vector<int>dx = vector<int>{1, 0 , -1, 0};
    vector<int>dy = vector<int>{0 , 1, 0, -1};
    vector<char>dir = vector<char>{'D' , 'R' , 'U' , 'L'};
    
    string alphabetBoardPath(string target) {
        string ans = "";
        char prev = 'a';
        for(int i = 0; i < 26; ++i) {  //cooordinates for each character [ row , col ]
            mp[i+'a'] = {i/5, i%5};
        }
        for(auto ch: target){
            string temp = bfs(prev, ch);
            prev = ch;
            ans += temp;
        }
        return ans;
    }
    
    string bfs(char beg , char target){
        int bx = mp[beg].first;  // x coord of beg ch
        int by = mp[beg].second;  // y coord of beg ch
        int tx = mp[target].first;  // x coord of target ch
        int ty = mp[target].second;  // y coord of target ch
        
        pair<int, int> start = {bx, by};
        pair<int, int> end = {tx, ty};
        
        queue<pair<string , pair<int, int>>>q;
        q.push({"",start});
        map<pair<int, int> , bool >vis;
        
        while(!q.empty()){
            auto cur = q.front();
            vis[cur.second] = true;
            q.pop();
            if(cur.second==end){
                cur.first += '!';
                return cur.first;
            }
            
            for(int i = 0;i<4;i++){
                int newx = cur.second.first + dx[i];
                int newy = cur.second.second + dy[i];
                
                if(valid(newx, newy) and !vis[{newx, newy}] and board[newx][newy]!='*'){
                    q.push({cur.first + dir[i] , {newx, newy}});
                }
            }
            
        }
        
        return "";   // code will not reach here
        
    }
    
    
    bool valid(int x,int y){
        if(x>=6 || y>=5 || x<0 || y<0)
            return false;
        return true;
    }
    
};


/*

// NO NEED OF RECURSION, just find Manhattan distance and make straight lines path accordingly!


class Solution {
public:   
    vector< string > board = vector<string>{"abcde", "fghij","klmno","pqrst","uvwxy","z"}; 
    unordered_map<char, pair<int,int>> mp;

    
    string alphabetBoardPath(string target) {
        string ans = "";
        char prev = 'a';
        for(int i = 0; i < 26; ++i) {  //cooordinates for each character [ row , col ]
            mp[i+'a'] = {i/5, i%5};
        }
        for(auto ch: target){
            string temp = solve(prev, ch);
            prev = ch;
            ans += temp;
        }
        return ans;
    }
    
    string solve(char beg , char target){
        string res = "";
        int bx = mp[beg].first;  // x coord of beg ch
        int by = mp[beg].second;  // y coord of beg ch
        int tx = mp[target].first;  // x coord of target ch
        int ty = mp[target].second;  // y coord of target ch
        int dy = tx - bx;   // disatnce to be moved in y direction (bcz distance between 2 rows is vertical dist)
        int dx = ty - by;  // disatnce to be moved in x direction (bcz distance between 2 cols is horixontal dist)
        // cout<<bx<<" "<<by<<" "<<tx<<" "<<ty<<" "<<dx<<" "<<dy<<endl;
        
        char diry, dirx;
        if(bx==5 and by==0){  // if our beginning ch is 'z', then we need to move vertical first the horizonatal
             // assume moving from 'z' to 'l', if you cant go horizontal first, you get WA..
            
            if(dy>0){
                diry = 'D';
            }else if(dy<0){
                diry = 'U';
            }
            dy = abs(dy);
            while(dy--){
                res+= diry;  
            }
            
            if(dx>0){
                dirx = 'R';
            }else if(dy<0){
                dirx = 'L';
            }
            dx = abs(dx);
            while(dx--){
                res+= dirx;  
            }

        }
        else{  // else we need move horizontal first, then vertical
            
            // assume moving from 'l' to 'z', if you go vertical first you get WA..
            if(dx>0){
                dirx = 'R';
            }else if(dy<0){
                dirx = 'L';
            }
            dx = abs(dx);
            while(dx--){
                res+= dirx;  
            }

            if(dy>0){
                diry = 'D';
            }else if(dy<0){
                diry = 'U';
            }
            dy = abs(dy);
            while(dy--){
                res+= diry;  
            }
    
        }

       
        res+='!';
        return res;
        
    }
    
};


*/