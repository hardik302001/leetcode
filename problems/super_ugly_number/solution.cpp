// O(n*k)
//dp soln, same as ugly number 2

//in python it gives tle, idk why??


class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> superUglyNumbers;
        superUglyNumbers.push_back(1);  // first super ugly number
        int numPrimes = primes.size();
        vector<int> idxs(numPrimes, 0);
        // add super ugly number up to nth 
        
        while(superUglyNumbers.size() < n)
        {
            int nextSuperUglyNumber = INT_MAX;   // next super ugly number
            for(int i = 0; i < numPrimes; i++)
            {
                nextSuperUglyNumber = min(nextSuperUglyNumber, superUglyNumbers[idxs[i]]*primes[i]);
            }
            for(int i = 0; i < numPrimes; i++)
            {
                if(nextSuperUglyNumber == superUglyNumbers[idxs[i]]*primes[i])
                {
                    idxs[i]++;
                }
            }
            superUglyNumbers.push_back(nextSuperUglyNumber);
        }
        
        return superUglyNumbers[n-1];
    }
};