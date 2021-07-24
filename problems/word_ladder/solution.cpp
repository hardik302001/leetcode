class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> hash(wordList.begin(), wordList.end());
        unordered_set<string> hash2(wordList.begin(), wordList.end()); //copy of hash to keep eye on used elemnts, so that they may not be used again resulting in TLE, see below we are directly comparing curr_word with elements of hash, so we can not simulatneously delete from hash, that why we are deleting from hash2, and after traversal of all elements from hash, we are m=doing hash = hash2, so that now our hash will have deleted elements, and hash and hash2 are also same..
        
        
        if(hash.find(endWord) == hash.end()) return 0;      //if the end word is not present int the wordlist return 0
        
        queue<string> q;
        q.push(beginWord);
        int no_of_words = 1;
        
        while(!q.empty()) {
           int size = q.size();
            
            for(int i = 0; i<size; i++) {
                string curr_word = q.front();
                q.pop();

                //when we find the endword return the shortest transformation count
                if(curr_word == endWord) return no_of_words;  
                
                for(auto it: hash){  // we are directly comparing from elements of hash, so we cant erase the used elements simulatenously while traversing...
                    int difference = 0;
                    for(int ch = 0;ch<it.size();ch++){
                        if(it[ch]!=curr_word[ch]){
                            difference++;
                        }
                    }
                    
                    if(difference == 1){
                        //cout<<it<<" ";
                        q.push(it);
                        hash2.erase(it);
                    }
                }
                
                hash = hash2;  // to keep track of deleted elements
                
            }
            
            no_of_words++;
            
        }
        
        return 0;
    }
};



//OTHER WAY TO DO THE COMPARING THING

//WE CAN ALSO KEEP A VISITED VECTOR TO AVOID  REDUNDANT CHCEKING

/*



                for(int i = 0; i<curr_word.size(); i++) {               // this loop will convert the word
                    string new_word = curr_word;
                    for(char letter = 'a'; letter <= 'z'; letter++) {
                        new_word[i] = letter;       
						
             //for every index, it will choose a new character & make a new word and 
            //if it is present in the hash set, then we push it in the queue and erase it from the hashset
                       
						
                        if(hash.find(new_word) != hash.end() and curr_word != new_word )             
                            q.push(new_word);
                            hash.erase(new_word);
                    }
                } 








*/

