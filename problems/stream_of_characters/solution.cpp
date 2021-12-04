
class TrieNode{
public:
    int endOfWord;
    TrieNode* children[26];          //use array,better memory usage
    
    TrieNode()
    {
        endOfWord = false;
        for(int i = 0;i<26;i++){
            children[i] = NULL;   
        }
    }
};


class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for(string &x:words)
        {
            reverse(x.begin(),x.end());
            insert(x,root);
            if (x.size() > longest_word)
                longest_word = x.size();
            
        }
    } 
    deque<char> stream;                    //using deque is a better option rather than vector!
    bool query(char letter) {
        stream.push_front(letter);
        
        // keep in queries only the "longest word" last queries, because we don't need the other ones anymore
        if (stream.size() > longest_word)
            stream.pop_back();
        
        TrieNode* curr = root;
        for(int i = 0; i<stream.size(); i++)
        {
            int index = stream[i] - 'a';
            curr = curr->children[index];
            if(curr == NULL)
            {
                return false;                      //not even reached at end of the word
            }
            if(curr->endOfWord){
                return true;
            }
            
            
        }
        
        return curr->endOfWord;
    }
    
    
        
    /** Inserts a word into the trie. */
    void insert(string word,TrieNode* root) {
        TrieNode* curr = root;
        
        for(int i = 0; i<word.size(); i++)
        {
            int index = word[i] - 'a';
            
            if(curr->children[index] == NULL)
            {
                curr->children[index] = new TrieNode();
            }
            
            curr = curr->children[index];
        }
        
        curr->endOfWord = true;
    }

    
//---------------------------------------------------------------------------------------------
    
    ~StreamChecker(){                         //destructor: to free memory
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
    
    
    
private:  //GOOD PRACTICE TO KEEP ROOT NODE PRIVATE
    TrieNode* root;
    int longest_word = 0;
};

