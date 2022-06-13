// same as: https://leetcode.com/problems/minimum-genetic-mutation/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         set<string> dictionary;
    for(auto word : wordList) {
        dictionary.insert(word);
    }
    if(dictionary.find(endWord) == dictionary.end()) {
        return 0;
    }
    
    queue<string> bfs;
    int result = 1;   // bcz we want length of sequence , not no. of transformations
    bfs.push(beginWord);
    
    while(!bfs.empty()) {
        int size = bfs.size();
        while(size--) {
            string temp = bfs.front();
            bfs.pop();
            if(temp == endWord)
                return result;
            
            //comparing is done in O(26)*size of word here!
            // see prev TLE pproachh there it was count of word of size(size of word)* size of word
            for(int i = 0; i < temp.size(); i++) {
                string current = temp;
                for(char j = 'a'; j <= 'z'; j++) {
                    current[i] = j; 

                    if(current == temp)
                        continue;

                    if(dictionary.find(current) != dictionary.end()) {
                        bfs.push(current);
                        dictionary.erase(current);
                    }
                }
            }
        }
        
        result++;
    }
    return 0;
    }
};