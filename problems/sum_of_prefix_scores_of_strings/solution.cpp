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


class Solution {
public:
    void insert(TrieNode* root, string word) {
        TrieNode* curr = root;
        
        for(int i = 0; i<word.size(); i++)
        {
            int index = word[i] - 'a';
            
            if(curr->children[index] == NULL)
            {
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
            curr->endOfWord += 1;                  // update after going on to next node
           
        }
    }
    
    /** Returns if the word is in the trie. */
    int search(TrieNode* root , string word) {
        TrieNode* curr = root;
        int p = 0; 
        
        for(int i = 0; i<word.size(); i++)
        {
            int index = word[i] - 'a';
            if(curr->children[index] != NULL)
            {
                curr = curr->children[index];
                p+= curr->endOfWord;
            }
            else{   
                return p;                  
            }              
        }    
        return p; //reached end of word, now endOfWord will decide whether such word exists that end at this curr position
    }

    
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(auto w: words){     
            insert(root, w);
        }    
        
        vector<int>ans;
        for(auto w: words){
            int cc = search(root, w);
            ans.push_back(cc);
        }
        
        return ans;

    }
};