class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size()>t.size()) return false;
        int j = 0;
        for(int i=0 ; i<t.size() ; ++i){
            if(t[i] == s[j]){
                ++j;
            }
        }
        return (j == s.size());
    }
};


// FOLLOW UP
/*

class Solution {
public:
    bool isSubsequence(string s, string t) {
        //build a record the index of each char in t
        vector<vector<int>> record(26);
        //add indexs
        for(int i = 0; i < t.size(); i++) {
            record[t[i]-'a'].push_back(i);
        }
        //check if each char in s is in the legal place
        int index = -1;
        for(int i = 0; i < s.size(); i++) {
            auto iter = upper_bound(record[s[i]-'a'].begin(), record[s[i]-'a'].end(), index);
            if(iter == record[s[i]-'a'].end()) return false;
            index = *iter;
        }
        return true;
    }
};


auto iter = upper_bound(record[s[i]-'a'].begin(), record[s[i]-'a'].end(), index);
What does this line do ? Why is index -1 initially

trying to find the first index greater than the passed in index that has that character in s[i],
smallest index valid would be a 0. so -1 to ensure it grabs any index possible. ( 0 ->> .. )

*/