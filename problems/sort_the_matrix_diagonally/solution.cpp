// Its a simple sorting question.This is not optimal solution but a simple one.

// Here we are traversing through 1st row and 1st column to get all the diagnol elements , seperately. I wrote a SOLVE function where it takes the matrix, and stores all the diagonal elements in a vector and sort it seperately.And changes the matrix!!!!!!!!!

class Solution {
public:
    void solve(int i,int j,vector<vector<int>>& mat)
    {
        vector<int> hey;
        int ti=i,tj=j;
        while(ti<mat.size()&&tj<mat[0].size())
        {
            hey.push_back(mat[ti][tj]);ti++;tj++;
        }
        sort(hey.begin(),hey.end());
        for(auto x : hey)
        {
            mat[i][j]=x;i++;j++;
        }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        if(mat.size()==1||mat[0].size()==1) return mat;
        for(int i=0;i<mat[0].size();i++)
        {
            solve(0,i,mat);
        }
        for(int i=1;i<mat.size();i++)
        {
            solve(i,0,mat);
        }
        return mat;
    }
};