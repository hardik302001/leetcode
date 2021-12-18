// Take N = 2563, D = {"1", "2", "6"} as an example,
// The first loop handles the count of x, xx, xxx which x belongs to D. the sum is 3^1 + 3^2 + 3^3.
// The second loop handles xxxx from left most digit.
// For example,
// count of 1xxx is 3^3
// count of 21xx is 3^2
// count of 22xx is 3^2

// If the elements of D can compose entired N, answer + 1
// Although it could be coded in a single loop, the logic would be unclear to me. I keep them seperated.

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        string NS = to_string(N);
        int digit = NS.size(), dsize = D.size(), rtn = 0;
        
        for (int i = 1 ; i < digit ; ++i)
            rtn += pow(dsize, i);
        
        for (int i = 0 ; i < digit ; ++i) {
            bool hasSameNum = false;
            for (string &d : D) {
                if (d[0] < NS[i]) 
                    rtn += pow(dsize, digit - i - 1);
                else if (d[0] == NS[i]) 
                    hasSameNum = true;
            }
            if (!hasSameNum) return rtn;
        }               
        return rtn+1;
    }
};