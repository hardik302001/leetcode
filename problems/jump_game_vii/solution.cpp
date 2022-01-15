// we know its a bfs problem, but simple problem will give tle! why bcz , even after marking them visited we will traverse and chcek if it is visited or not! same as what we did in jump game 4
// see for more info : https://leetcode.com/problems/jump-game-vii/discuss/1224963/BFS-C%2B%2B-Explained


// we were also getting tle there also, so we need to do pruning for same

// same as : https://leetcode.com/problems/jump-game-iv/

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if(s[n-1]!='0')
            return false;
        
        int i = 0;
        queue<int> q;
        q.push(0);
        int curr_max = 0;
        
        while(!q.empty()){
            i = q.front();
            q.pop();
            if(i == n-1)
                return true;
            
            for(int j = max(i + minJump, curr_max); j <= min(i + maxJump, n - 1); j++){
                if(s[j] == '0')   q.push(j);
            }   
            curr_max = min(i+maxJump+1, n-1);   // pruning, magic line
        }
        return false;
    }
};