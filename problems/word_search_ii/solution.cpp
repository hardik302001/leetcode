//Trie implementation
//code idea similar to : https://leetcode.com/problems/replace-words/
//also see: https://leetcode.com/problems/implement-magic-dictionary/

class TrieNode{
public:
    
    TrieNode* children[26];
    bool isEndOfWord;
    int count;
    
    TrieNode()
    {
        memset(children, 0, 26*sizeof(TrieNode*));
        isEndOfWord = false;
        count = 0;
    }
};

class Trie{

    TrieNode* root;
    
public:
    
    Trie()
    {
        root = new TrieNode();
    }
    
    TrieNode* getRoot()
    {
        return root;
    }
    
    void addWord(string word)
    {
        TrieNode* curr = root;
        
        for(auto const& letter : word)
        {
            int index = letter - 'a';
            if(curr->children[index] == NULL)
                curr->children[index] = new TrieNode();
            curr = curr->children[index];
            curr->count++;
        }
        curr->isEndOfWord = true;
    }
    
    void removeWord(string &word)
    {
        TrieNode* curr = root;
        for(auto const& letter : word)
        {
            int index = letter - 'a';
            if(curr->children[index] == NULL)
                return;
            curr = curr->children[index];
            curr->count--;
        }
        curr->isEndOfWord = false;
    }
};

class Solution {
    
    void DFS(int x, int y, vector<vector<char>>& board, Trie* &trie, TrieNode* root, vector<string> &ans, string &path)
    {
        int ind = board[x][y] - 'a';
        if(ind >= 0 && ind < 26 && root->children[ind] != NULL && root->children[ind]->count > 0)
        {
            path.push_back(board[x][y]);
            char cell = board[x][y];
            board[x][y] = '*';
            
            if(root->children[ind]->isEndOfWord)
            {
                ans.push_back(path);
                trie->removeWord(path);
            }
                
            
            int directions[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
            
            for(auto const& d : directions)
            {
                int x1 = x + d[0];
                int y1 = y + d[1];
                
                if(x1 < 0 || x1 >= board.size() || y1 < 0 || y1 >= board[0].size())
                    continue;
                
                DFS(x1, y1, board, trie, root->children[ind], ans, path);
            }
            board[x][y] = cell;
            path.pop_back();
        }
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        Trie* trie = new Trie();
        
        vector<string> ans;
        string path = "";
        
        for(auto const& word : words)
            trie->addWord(word);
        
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                DFS(i, j, board, trie, trie->getRoot(), ans, path);
            }
        }
        
        
        return ans;
    }
};