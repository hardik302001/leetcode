

class Solution {
public:    
    int dfs(string s, int idx, vector<int>& memo)
    {
        int n = s.size();
        if (idx >= n) return 0;
        if (memo[idx] != -1) return memo[idx];
        
        int res = 1;
        string cur;
        for(int i = idx; i < n; i++)
        {
            cur += s[i];
            if (cur.size() <= (n-i))
            {
                if (cur == s.substr(i+1, cur.size()))
                {
                    res = max(res, dfs(s, i+1, memo) + 1);
                }
            }
        }
        return memo[idx] = res;
    }
    

    int deleteString(string s) {
        
        int n = s.size();
        if (n == 0) return 0;
        unordered_map<char, int> freq;
        for(auto ch : s)
            freq[ch]++;
        
        if (freq.size() == 1 && n > 1) return n;
        
        vector<int> memo(4001, -1);
        return dfs(s, 0, memo);
    }
};
