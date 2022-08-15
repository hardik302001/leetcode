class AuthenticationManager {
public:
    
    int t;
    unordered_map<string , int>m;
    AuthenticationManager(int timeToLive) {
        t = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        m[tokenId] = currentTime+t;
    }
    
    void renew(string tokenId, int currentTime) {
        if(m.count(tokenId) and m[tokenId]>currentTime){
            m[tokenId] = currentTime+t;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int c = 0;
        for(auto p: m){
            if(p.second>currentTime){
                c++;
            }
        }
        
        return c;
    }
};
