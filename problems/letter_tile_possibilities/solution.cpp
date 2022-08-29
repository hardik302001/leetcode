class Solution {
public:
    set<string> res;
    string curr="";
    unordered_map<int, bool> vis;
    
    void solve(string tiles)
    {
        if(curr.size()>tiles.size()) 
            return;
        res.insert(curr);
        
        for(int i=0;i<tiles.size();i++)
        {
            if(vis[i]) 
                continue;
            curr+=tiles[i];
            vis[i] = true;
            solve(tiles);
            curr.pop_back();
            vis[i] = false;
        }
    }
    
    int numTilePossibilities(string tiles) {

        solve(tiles);

        return res.size()-1;
    }
};