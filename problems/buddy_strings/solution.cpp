/*


If A.length() != B.length(): no possible swap

If A == B, we need swap two same characters. Check is duplicated char in A. //not all same chars

In other cases, we find index for A[i] != B[i]. There should be only 2 diffs and it's our one swap.

*/

class Solution {
public:
    bool buddyStrings(string A, string B) {

        if (A.length() != B.length()) return false;
        if (A == B && set<char>(A.begin(), A.end()).size() < A.size()) return true;

        vector<int> diff_pos;
        for(int i = 0; i < A.size(); i++) {
            if(A[i] != B[i])
                diff_pos.emplace_back(i);
        }

        // only one pair of diff positions, check if swapping makes them equal
        if(diff_pos.size() == 2) {
            swap(A[diff_pos[0]], A[diff_pos[1]]);
            return A==B;
        }
        else{
            return false;
        }
    }
};
        
        
