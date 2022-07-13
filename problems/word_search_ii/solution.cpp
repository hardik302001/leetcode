//Trie implementation
//code idea similar to : https://leetcode.com/problems/replace-words/
//also see: https://leetcode.com/problems/implement-magic-dictionary/

class TrieNode{
public:
    bool end;
    TrieNode* children[26];
    TrieNode(){
        end = false;
        for(int i = 0;i<26;i++){
            children[i] = NULL;
        }
    }
};


    

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        //build trie
        TrieNode* root = new TrieNode;          
        /*
        //here no constructor, so we declare it likr object..
        //if there was some constructor like below, so instantiate it like this 
        
                Trie() {
                    root = new TrieNode();
                }
                
                private:
                    TrieNode root;    
        
        */
        
        
        /* INSERT FUNCTION  */ 
        for(string word:words){
            TrieNode* cur = root;
            for(char c : word){
                if(cur->children[c-'a'] == NULL) cur->children[c-'a'] = new TrieNode;
                cur = cur->children[c-'a'];
            }
            cur->end = true;
        }
        
        
        int n=board.size();
        if(n==0)
        {
            return {};
        }
        int m=board[0].size();
        
        vector<string> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                search(board,i,j,ans, root);       //we need to explicityly pass root, bcz root is declared inside this function, it is not glovbal
            }
        }
        
        clear(root);
        return ans;
        
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
    
    
    
    void helper(vector<vector<char>>& board,int x,int y,TrieNode* curr,vector<string>&ans,string temp)
    {
        int n=board.size();
        int m=board[0].size();
        
        if(x<0 || y<0 || x>=n ||y>=m || board[x][y]=='#')
        {
            return;
        }
        
        if(curr->children[board[x][y]-'a']==NULL)             //most impo step, we traverse if , children[board[x][y]- 'a']!=NULL
        {
            return ;
        }
        
        temp+=board[x][y];
        curr=curr->children[board[x][y]-'a'];       //it is not NULL, so we will traverse
        if(curr->end)
        {
            ans.push_back(temp);
            curr->end=false;
        }
        char c = board[x][y];
        board[x][y] = '#';
        helper(board,x+1,y,curr,ans,temp);
        helper(board,x,y+1,curr,ans,temp);
        helper(board,x-1,y,curr,ans,temp);
        helper(board,x,y-1,curr,ans,temp);
        board[x][y]=c;                        //backtrack
    }
    
    
    
    
    void search(vector<vector<char>>& board,int x,int y,vector<string>&ans, TrieNode* root)
    {
        TrieNode* curr = root;
        return helper(board,x,y,root,ans,"");
    } 
};









