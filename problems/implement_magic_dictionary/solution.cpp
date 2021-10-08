//see PYTHON SOLUTION FOR HASHMAP IMPLEMENTATION


//this is trie based solution




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



class MagicDictionary {
public:
    MagicDictionary() {
        root = new TrieNode();
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto it: dictionary){
            insert(it, root);
        }
    }
    
    bool helper(string word)
    {
        TrieNode* curr = root;
        for(int i = 0; i<word.size(); i++)
        {
            int index = word[i] - 'a';
            curr = curr->children[index];
            if(curr == NULL)
            {
                return false;                      //not even reached at end of the word
            }       
        }
        return curr->endOfWord;
    }
    
    bool search(string sword) {
        int n=sword.size();
        string word=sword;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<26;j++)
            {
                if('a'+j==sword[i])
                    continue;
                word[i]='a'+j;
                if(helper(word))
                    return true;
            }
            word[i]=sword[i];
        }
        return false;
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
    
    ~MagicDictionary(){                         //destructor: to free memory
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
    
};

