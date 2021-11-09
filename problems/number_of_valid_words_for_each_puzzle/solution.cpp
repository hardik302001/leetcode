//bitmask + hashing
// https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/discuss/1567327/C%2B%2B-EASY-INTUITIVE-SOL-oror-BIT-MANIPULATION-oror-FULL-EXPLANATION


class Solution {
public:
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        
        map<char, vector<int>>mp;
        
		// Initialize the map for each char in alphabet with empty vector
        for(int i = 0; i<26; ++i){
            vector<int>v;
            mp[char(i + 'a')] = v;
        }
        
        
        //find mask of every word and push that mask for every char in that word..why?
        //so that we can see which all word were having starting char of puzzle...
        for(auto &word:words){
            int mask = bitmask(word);
            
			//This is a checker that will help us NOT to incluce same word twice in our map for some character
            vector<bool>letter_found(26, 0);
            
            for(auto &letter: word){
                if(letter_found[letter - 'a'] == 0){
                    mp[letter].push_back(mask);
                    letter_found[letter - 'a'] = 1;
                }
            }
        }
        
        
        
        vector<int>res;
        
        for(auto &puzzle: puzzles){
            
            char first_char = puzzle[0];
            int cnt = 0;
            int puzzle_mask = bitmask(puzzle);
            
			//Get our desired vector of bitmasks of words that contains our first char of puzzle
            for(auto word_mask: mp[first_char]){
			
				//check if all letter is contained by puzzle or not
                if((word_mask & puzzle_mask) == word_mask)             //think, this is the most OP step of solution..if in word and not in puzzle then AND = 0, so result will not hve that bit set..so it wont be equal to word_mask now!
                                                                    //we can also do a for loop of size 2 and then match each bit..
                    cnt++;
            }
            // Add the count for current puzzle
            res.push_back(cnt);
        }
        
        return res;
    }
    
    
    
    int bitmask(const string& word) {
        // Build a bitmask of chars to represent each word
        // the builtin std::bitset also works
        int mask = 0;
        for (char letter : word) {
            mask |= 1 << (letter - 'a');
        }
        return mask;
    }
    
    
};
