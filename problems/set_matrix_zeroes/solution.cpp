/*
courtesy TUF
https://www.youtube.com/watch?v=M65xBewcqcI

3 methods discussed
1. brute: change all rows and cols with zero to INF(that element i.e. isnot present in matrix ,,bcz if we make it 0 now only,, then we wont be able to differentiat ebetween old 0 and new 0 ,so we change old 0 to such value that is not present in the matrix , so we took INF. )
    traverse again...and change all INF's to 0
    
    TC: O(N*M)(N+M)
    SC = O(1)
    
2. make seperately a col array and a row array...traverse matrix ..for all mat[i][j]==0 mark row[j] = 0 and col[i] = 0
    traverse again..and if for mat[i][j] if (row[j] or col[i])==0 then mat[i][j] = 0
    TC = O(M*N + M+N)
    SC: O(N) + O(M)
    
    
3. mujhe smjh nhi aaya aache se...wo col= 1 to col = 0 wala logic ( i guess to keep track for first col)  o striver ne bola...but ignlre it..see below code.
It is optmisation of SECOND approach, there we took speerate vectors for row and column, to keep trackof zero and one,

we can optimise it by taking these both vectors as first column and first row of the matrix..
but we cant make them 0 in beginning only...bcz then we cant keep track of new and old zero..so we will take 2 variable..isrow and iscol...rest you can understand by code
!
    
    TC = 2*O(M*N)
    SC = O(1)
    



*/


// DO LOOK AT PREIOVOUS CODE..IT IS BETTER VERSION OF PERVIOUS CODE
class Solution {
public:
    
    void setZeroes(vector<vector<int>>& matrix) {
        bool isZeroCol = false;
        bool isZeroRow = false;
        for (int i = 0; i < matrix.size(); i++) { //check the first column
            if (matrix[i][0] == 0) {
                isZeroCol = true;
                break;
            } 
        }
        for (int i = 0; i < matrix[0].size(); i++) { //check the first row
            if (matrix[0][i] == 0) {
                isZeroRow = true;
                break;
            } 
        }
        for (int i = 1; i < matrix.size(); i++) { //check except the first row and column
            for (int j = 1; j < matrix[0].size(); j++) 
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        }
        for (int i = 1; i < matrix.size(); i++) { //process except the first row and column
           for (int j = 1; j < matrix[0].size(); j++) 
               if (matrix[i][0] == 0 or matrix[0][j] == 0)
                   matrix[i][j] = 0;
        }
        if (isZeroCol) { //handle the first column
            for (int i = 0; i < matrix.size(); i++) 
                matrix[i][0] = 0;
        }
        if (isZeroRow) { //handle the first row
            for (int i = 0; i < matrix[0].size(); i++) 
                matrix[0][i] = 0;
        }
    }
};