

/*

Approach:

We can write only one word in encoded string for that word and all its suffixes.
For example :
Words freetime, time and me can be encoded as freetime# and the nums array [0,4,6]. So we take only the parent string and exclude all its suffixes in encoded string.

We sort the array from longest to the shortest. So that no word before one word can be its suffix (As length of suffix < length of word)

Now we enter all the words in a hash map to keep track which words are included in the encoded string.

We run a loop where we add length of the word + 1(for #) to the ans if the word is present in hash map.

Next we run another loop where we find all the suffix of the word and make their count 0 in the map as they will be already covered by its parent string.

Finally return the ans.

Code with explanation:



*/
class Solution {
public:
    static bool compare (string& first, string& second) {
        return first.size() > second.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
        unordered_map<string, int> mp;
        int ans = 0;
        
        //sorting the array in decreasing length sequence
        sort(words.begin(), words.end(), compare);

        //Entering each word in hash map.
        for(int i=0; i<words.size(); i++){
            mp[words[i]]++;
        }
        
        //For each word if it exist in hash map then add its length+1 to ans as # is also included.
        for(int i=0; i<words.size(); i++){
            int k = words[i].size();
            if(mp[words[i]] >0){
                ans += (k+1);
            }
            
            //Deleting record of any suffix of the word from hash map as it is already covered.
            for(int j=k-1; j>=0; j--){
                string s = words[i].substr(j, k-j);
                mp[s] = 0;
            }
        }
        return ans;
    }
};


