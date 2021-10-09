//Trie implementation
//code idea similar to : https://leetcode.com/problems/replace-words/
//also see: https://leetcode.com/problems/implement-magic-dictionary/

class TrieNode{
public:
    bool end;
    TrieNode* children[256];
    TrieNode(){
        end = false;
        for(int i = 0;i<256;i++){
            children[i] = NULL;
        }
    }
};


    

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        //build trie
        TrieNode* root = new TrieNode;          
        /*
        //here no constructor, so we declare it liek object..
        //if there was some constructor like below, so instantiate it like this 
        
                Trie() {
                    root = new TrieNode();
                }
                
                private:
                    TrieNode root;    
        
        */
        
        
        /* INSERT FUNCTION  */ 
            TrieNode* cur = root;
            for(char c : word){
                if(cur->children[c-'A'] == NULL) cur->children[c-'A'] = new TrieNode;
                cur = cur->children[c-'A'];
            }
            cur->end = true;
        
        
        
        int n=board.size();
        if(n==0)
        {
            return {};
        }
        int m=board[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(search(board,i,j, root)){clear(root); return true;}       //we need to explicityly pass root, bcz root is declared inside this function, it is not glovbal
            }
        }
        
        clear(root);
        return false;
        
    }
    
    
    
    
    
    void clear(TrieNode* root)
    {
        for(int i = 0; i<256; i++)
        {
            if(root->children[i] != NULL)
            {
                clear(root->children[i]);
            }
        }
        
        delete root;
    }
    
    
    
    bool helper(vector<vector<char>>& board,int x,int y,TrieNode* curr)
    {
        int n=board.size();
        int m=board[0].size();
        
        if(x<0 || y<0 || x>=n ||y>=m || board[x][y]=='#')
        {
            return false;
        }
        
        if(curr->children[board[x][y]-'A']==NULL)             //most impo step, we traverse if , children[board[x][y]- 'a']!=NULL
        {
            return false;
        }
        
        curr=curr->children[board[x][y]-'A'];       //it is not NULL, so we will traverse
        if(curr->end)
        {
            curr->end=false;
            return true;
        }
        char c = board[x][y];
        board[x][y] = '#';
        if(helper(board,x+1,y,curr) or helper(board,x,y+1,curr) or helper(board,x-1,y,curr) or helper(board,x,y-1,curr)){return true;};
        board[x][y]=c;                        //backtrack
        return false;
    }
    
    
    
    
    bool search(vector<vector<char>>& board,int x,int y, TrieNode* root)
    {
        TrieNode* curr = root;
        return helper(board,x,y,curr);
    }

    
    
};









