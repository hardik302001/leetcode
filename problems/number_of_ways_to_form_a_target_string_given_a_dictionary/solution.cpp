#define ll long long

class Solution {
public:
    const ll MOD = 1e9 + 7; // Using long long for MOD to avoid overflows
    
    int n;  // Length of word
    vector<vector<ll>> freq, mem;
    string target;
    
    // DFS : Takes in current index of word and target
    int go(int w, int t) {
        
        // If we exceed target's length, we've matched everything in target
        if(t >= target.size()) 
            return 1;
        
        // Else if we exceed word's length, we haven't matched target
        if(w >= n) 
            return 0;
        
        // If we've processed this before, return the value from the memoization table
        ll &ans = mem[w][t];
        if(ans != -1) 
            return ans;
        
        int cur = target[t] - 'a';
        
        // Else return the sum of :
        //   1) Don't match the current character of target to current index of word (go(w + 1, t))
        //   2) Match the current character of target to word (freq[w][cur] * go(w + 1, t + 1))
        // Note: There are freq[w][cur] options to choose the current letter, hence the multiplier 
        // Note: MOD's are needed to avoid overflows - apply MOD after every operation        
        return ans = (go(w + 1, t) + ((freq[w][cur] * go(w + 1, t + 1)) % MOD)) % MOD;
    }
    int numWays(vector<string>& words, string _target) {
        target = _target;
        int i, j, m = words.size();
        n = words[0].size();
        freq.resize(n, vector<ll>(26, 0));
        mem.resize(n + 1, vector<ll>(target.size() + 1, -1));
        
        // Build a frequency table indexed by word position
        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
                freq[j][words[i][j] - 'a']++;
        
        return go(0, 0);
    }
};