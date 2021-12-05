//COURTESY: CODING SIMPLIFIED 20 MINS VIDEO TITLED STRING 15: LONGEST SUBSTRING WITH SAM ELETTER IF AT MAX K CHARATERS CAN BE REPLACED

class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0;
        int end = 0;
        int max_length = 0;
        int max_freq = 0;
        unordered_map<char,int>mp;
        
        while(end<s.length()){
            char cur = s[end];
            mp[cur]++;                          //taking freq
            max_freq = max(max_freq, mp[cur]);  //max freq of that window (window = end-start+1), why mp[cur]?? bcz in line no 14, freq map is updated , so we need to update max_freq also
            
            while(  ( end-start+1) - max_freq> k){   //we have only k choices to remove ..if window len with k replacement goes out of range then we remove from starting..
                char startchar = s[start];
                mp[startchar]--;   //dec char count for that char...bcz it will not be counted in that window
                start++;
                for(auto it: mp){
                    max_freq = max(max_freq, it.second);
                }
            }
            max_length = max(max_length, end-start+1);   //max length of that window
            end++;
        }
        
        
        return max_length;
    }
};