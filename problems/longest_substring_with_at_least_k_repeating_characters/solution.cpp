// SLIDING WINDOW UNIQUE

/*

Steps to approach this problem :
First select the number of unique elements which should constitute the answer substring.
they can be [1, 26]
Now in a helper function keep the count of :

ending pointer
starting pointer
current unique elements
number of elements with count at least k
In the helper function slide through the entire string and check if there is a window where "number of unique characters"(currunique) == "number of characters with frequency at least K"(numk) and update the running counter and return it.

k : freq of each character of our output substring should be >= k.
totalUnique: number of unique characters that should be present in our output substring
currUnique : number of unique characters we have encountered uptil now
numk : number of characters out of all currUnique characters that have freq >= k
start , end : pointers
cnt : maxumum length of output substring that have totalUnique characters!

*/

class Solution {
public:

    int solver(string &s, int &k, int &totalUnique) {
        int start=0, end=0, currunique=0, numk=0;
        int cnt = 0;
        vector <int> chMap(26, 0);
        while(end < s.size()) {
            if (!chMap[s[end] - 'a']) currunique++;
            chMap[s[end]-'a']++;
            if (chMap[s[end] - 'a'] == k) numk++;
            end++;
            while(currunique > totalUnique) {
                if (chMap[s[start] - 'a'] == k) numk--;
                chMap[s[start]-'a']--;
                if (!chMap[s[start] - 'a']) currunique--;
                start++;
            }
            // number of unique elements are equal to the number of elements which have count of at least k
            if (currunique == numk) {
                cnt = max(cnt, end-start);
            }
        }
        return cnt;
    }
    
    
    int longestSubstring(string s, int k) {
        int n = s.size();
        int cnt = 0;
        for(int i =1; i<=26; i++) {
            cnt = max(cnt, solver(s, k, i));
        }
        return cnt;
    }

};