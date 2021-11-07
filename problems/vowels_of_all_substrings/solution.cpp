class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };
public:
    long long countVowels(string s) {
        long long N = s.size(), ans = 0;
        for (long long i = 0; i < N; ++i) {
            if (!isVowel(s[i])) continue;
            ans += (i + 1) * (N - i);
        }
        return ans;
    }
};