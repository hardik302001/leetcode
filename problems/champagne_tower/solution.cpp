//see the dp matrix will shud of size 100 x 100 , why bcz (0 to 99)

//but we will consider of size 101 x 101, why bcz if we want to decide for
//outcome of row r, then we need to decide outcome of row r+1, then only we will confirm outcome of row r

// when we would be at row 98, and we fill all row 98 and extra to row 99, then we are confirming outcome for row 98 not row 99, 
//why not for row 99, bcz we can fill more on row 99, so when we will fill for row 100 then we would be sure for row 99!
//so we need 101 x 101 matrix


class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector< vector <double> > result(101, vector< double >(101,0.0));
	        //it is like a right angled triangle!
	        //after l[i][j], we have l[i][j+1] and l[i+1][j+1]
	        
	        result[0][0] = poured;
	        for (int i = 0; i <= (query_row); i++) {
	            for (int j = 0; j <= (i); j++) {
	                if (result[i][j] >= 1) {
	                    result[i + 1][j] += (result[i][j] - 1) / 2.0;
	                    result[i + 1][j + 1] += (result[i][j] - 1) / 2.0;
	                    result[i][j] = 1;
	                }
	            }
	        }
        return result[query_row][query_glass];
	}
    
};