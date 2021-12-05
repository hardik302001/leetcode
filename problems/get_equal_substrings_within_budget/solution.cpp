class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int l = 0;
        int cost = 0;
        int ans = 0;
        int n = s.size();
        for (int r = 0;r<n;r++){
            cost = cost + abs(s[r] - t[r]);
            while(cost>maxCost){
                cost = cost - abs(s[l] - t[l]);
                l = l + 1;
            }
            
            ans = max(ans, r-l+1);
        }
        
        return ans;
    }
};