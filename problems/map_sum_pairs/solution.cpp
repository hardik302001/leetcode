class TrieNode{
public:
    int endOfWord;
    TrieNode* children[26];          //use array,better memory usage
    int score;
    TrieNode()
    {
        endOfWord = 0;
        for(int i = 0;i<26;i++){
            children[i] = NULL;   
        }
        score = 0;
    }
};


class MapSum {
public:
    unordered_map<string, int>m;
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string word, int val) {
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
        curr->score = val;    //bcz score is overriden, so we cant do prefix sum here one, we need to wait!
        curr->endOfWord += 1;
    }
    
    
    int sum(string prefix) {
        res = 0;
        TrieNode* curr = root;
        for(char c : prefix) {
            if(curr->children[c-'a']==NULL) 
                return 0;
            curr = curr->children[c-'a'];
        }
        helper(curr);        //now i m at last char of prefix
        return res;
    }
    
    void helper(TrieNode* curr) {
        res += curr->score;    //pref sum of all strings greater than curr string
        for (int i = 0; i < 26; i++) {
            if (curr->children[i] != NULL) {
                helper(curr->children[i]);
            }
        }
    }
    
    
    //----------------------------------------------
    
        ~MapSum(){                         //destructor: to free memory
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
    int res;
};

