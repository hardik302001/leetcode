class TrieNode{
public:
    int endOfWord;
    TrieNode* children[26];
    TrieNode(){
        endOfWord = false;
        for(int i = 0;i<26;i++){
            children[i] = NULL;
        }
    }
    
};



class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(int i = 0;i<word.size();i++){
            int index = word[i]-'a';
            if(cur->children[index]==NULL){
                cur->children[index] = new TrieNode();
            }
            cur = cur->children[index];
        }
        cur->endOfWord = true;
    }
    
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
    
    bool searchHelper(string &word, int index, TrieNode* cur) {
        // BASE CASE
        if (index == word.length()) {
            return cur->endOfWord;
        }

        char curChar = word[index];

        // when char is defiend
        if (curChar != '.') {
            if (cur->children[curChar - 'a']==NULL)
                return false;
            else
                return searchHelper(word, index + 1, cur->children[curChar - 'a']);    //directly return true/false, bcz we have only one path...no choices..so if that path matches return true, else return false
        }
        else{
            // when char is undefiend
            for (int i = 0; i < 26; i++) {
                if (cur->children[i]) //only consider the case which can give uss a match, else we ignore the unmatching cases..and return false only when we have used all our choices
                    if(searchHelper(word, index + 1, cur->children[i])){ return true;}    //only return if we found a match , else we will check for more combinations
            }
            
            return false;  //all combinations used,but still no match, so return false
        }
        // return false;
    }
    
    
    
            
    ~WordDictionary(){                         //destructor: to free memory
        clear(root);
    }
    
    void clear(TrieNode* root)
    {
        for(int i = 0; i<26; i++)
        {
            if(root->children[i] != NULL)
            {
                clear(root->children[i]);
            }
        }
        
        delete root;
    }

private:
    TrieNode* root;
};
