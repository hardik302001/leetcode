class Solution {
public: 
int countVowelSubstrings(string s) {
        int res = 0;
        string t = "";
        for (int i = 0; i < s.length(); i++) {

            // If current character is a vowel then append it to the t
            if (isVowel(s[i])) {
                t += s[i];
            }
            else {
                if (t.length() > 0) res += countSubstrings(t);
                t = "";
            }
        }
        if (t.length() > 0) res += countSubstrings(t);
        return res;
    } 
	
    int countSubstrings(string s) {
        int count = 0;
        map<char, int> mp;
        int n = s.length(), start = 0;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
            while (mp['a'] > 0 && mp['e'] > 0 && mp['i'] > 0 && mp['o'] > 0  && mp['u'] > 0) {
                count += n - i;        //bcz the string s is having all vowels..once we get all 5vowels, we can add rest of the left vowels
                mp[s[start]]--;
                start++;
            }
        }
        return count;
    }
     
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
};