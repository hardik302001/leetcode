// https://leetcode.com/problems/implement-trie-prefix-tree/discuss/1383755/C%2B%2B-SIMPLE-code-with-Memory-Management

/*
Most people would have constructed a Trie at least once before attempting this question. So, what is there to take away by solving it again? For C++ users, writing a destructor and deleting all initialized recursive nodes/tries is a key takeaway, and may be asked in an interview. Moreover, the way to delete is also clever since it requires recursive deletion, and lower nodes have to be cleared before higher nodes.

Another important point is using array instead of vector to save on memory. I frequently use vectors everywhere instead of classic arrays but in tries due to the large number of children nodes, arrays can save on memory.

I use TrieNode based implementation as I have learnt it that way and the code seems most clear to me as such. I also did not use an auxiliary function for search prefix method.
*/


//  VERY IMPORTANT SEE THIS !!
//leetcode implement-trie-prefix-ii (locked quetsion) ----
//                                                        |
//                                                       \|/
/****   https://zhenchaogan.gitbook.io/leetcode-solution/leetcode-1804-implement-trie-ii-prefix-tree    ***/

class TrieNode{
public:
    int endOfWord;
    TrieNode* children[26];          //use array,better memory usage
    
    TrieNode()
    {
        endOfWord = 0;
        for(int i = 0;i<26;i++){
            children[i] = NULL;   
        }
    }
};


class Trie {
public:

    Trie() {
        root = new TrieNode();
    }

    
    /** Inserts a word into the trie. */
    void insert(string word) {
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
        
        curr->endOfWord += 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
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
        
        return curr->endOfWord; //reached end of word, now endOfWord will decide whether such word exists that end at this curr position
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        
        for(int i = 0; i<prefix.size(); i++)
        {
            int index = prefix[i] - 'a';
            curr = curr->children[index];
            if(curr == NULL)
            {
                return false;                    //if not even reached till end of prefix, so false
            }
        }
        return true;
        
    }
    
    
//---------------------------------------------------------------------------------------------------------------------    
        
    ~Trie(){                         //destructor: to free memory
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