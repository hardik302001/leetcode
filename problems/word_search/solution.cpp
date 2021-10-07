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