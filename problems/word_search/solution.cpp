//Trie implementation
//code idea similar to : https://leetcode.com/problems/replace-words/
//also see: https://leetcode.com/problems/implement-magic-dictionary/
// // Time: O(mxn * 4) Worse case is traversing the entire grid 
// Space: O(mxn + wordLength) I created a new matrix to track visited  + a trie

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

//backtracking + dfs solution for the same!
// Space complexity O(Length of longest word) as space complexity = depth of recursion tree. Time complexity = O(n * m * 4^L) , where L = length of longest word. (as in every recursive call, we are calling the function 4 times, thus exponential complexity).

/*
class Solution {
public:
bool exist(vector<vector<char>>& board, string word) 
{
		if(board.empty())
			return false;
    
		for(int i=0; i<board.size(); i++)
		{
			for(int j=0; j<board[0].size(); j++)
			{
				if(dfs(board, 0, i, j, word))
					return true;
			}
		}
    
    return false;
}

bool dfs(vector<vector<char>>&board, int count, int i, int j, string& word)
{
    if(word.size() == count) //Signifies that we have reached the end of search
        return true;
    
    if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[count])
	return false;
    //We check if element is within bounds and then check if the character at that is the same as the corresponding character in string word
        

    char temp = board[i][j];
    board[i][j] = ' '; //To show that we have visited this node
    
    bool res = dfs(board, count+1, i+1, j, word) || dfs(board, count+1, i-1, j, word) || dfs(board, count+1, i, j+1, word) ||dfs(board, count+1, i, j-1, word); //DFS in all 4 directions
    
    board[i][j] = temp; //Restore the element after checking   , backtracking..bcz after chenging the value(marking visited) the matrix would be changed
    
    return res;
}
};

*/









