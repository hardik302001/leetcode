// https://leetcode.com/problems/word-subsets/discuss/1128123/Short-and-Easy-w-Explanation-or-O(A-%2B-B)-using-max-frequency-count-or-Beats-100


class Solution {
public:
    vector<int> countFreq(string& word){
        vector<int> freq(26);
        for(auto& c : word) freq[c - 'a']++;
        return freq;
    }
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> Maxfreq(26); // maintains minimum freq of each char required for a word to be universal word
        vector<string> ans;
        for(auto& word : B){
            vector<int> freq = countFreq(word);            
            for(int i = 0; i < 26; i++) Maxfreq[i] = max(Maxfreq[i], freq[i]);
        }        
        for(auto& word : A){
            vector<int> freq = countFreq(word);            
            int i = 0;
            for(;i < 26; i++) if(freq[i] < Maxfreq[i]) break;
            if(i == 26) ans.push_back(word);
        }
        return ans;
    }    
};