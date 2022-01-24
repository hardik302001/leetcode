// DP , beautiful problem
/*
For each book we have two choices, either place it in the current shelf or place it in a new shelf. Find the minimum from those two options. If we place it in a new shelf, we have to add the height of the previous shelf to the return value.
*/

class Solution {
public:
    
    vector<vector<int>>memo = vector<vector<int>>(1001 , vector<int>(1001, -1));
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        return helper(0, 0, books[0][1], books, shelf_width);
    }
    
    int helper(int cur, int curShelfWidth, int curShelfMaxHeight, vector<vector<int>> &books, int &shelf_width) {
        if (memo[cur][curShelfWidth] != -1) {
            return memo[cur][curShelfWidth];
        }
        
        // When there is no book left 
        if (cur == books.size()) {
            return curShelfMaxHeight;
        }
        
        int curBookWidth = books[cur][0];
        int curBookHeight = books[cur][1];
        int nextShelf, nextBook = INT_MAX;
        
        // Put the current book onto current shelf, and go to next book
        int newShelfWidth = curBookWidth + curShelfWidth;
        if (newShelfWidth <= shelf_width) {
            nextBook = helper(cur + 1, newShelfWidth, max(curShelfMaxHeight, curBookHeight), books, shelf_width);
        }
        
        // Put the current book onto next shelf
        nextShelf = helper(cur + 1, curBookWidth, curBookHeight, books, shelf_width) + curShelfMaxHeight;
        
        // Memoization
        memo[cur][curShelfWidth] = min(nextShelf, nextBook);
        return memo[cur][curShelfWidth];
    }
};