/*
A simple solution is to check if frequency of digits in N and all powers of 2 less than 10^9 are equal. In our case, we need to check for all powers of 2 from 2^0 to 2^29 and if any of them matches with digits in N, return true.

*/


class Solution {
public:
    // counts frequency of each digit in given number N and returns it as vector
    vector<int> countDigits(int N){
        vector<int>digitsInN(10);
        while(N)
            digitsInN[N % 10]++, N /= 10;
        return digitsInN;
    }
    bool reorderedPowerOf2(int N) {
        vector<int> digitsInN = countDigits(N); // freq of digits in N
        // powOf2 goes from 2^0 to 2^29 and each time freq of digits in powOf2 is compared with digitsInN
        for(int i = 0, powOf2 = 1; i < 30; i++, powOf2 <<= 1)
            if(digitsInN == countDigits(powOf2)) return true;  // return true if both have same frequency of each digits
        return false;
    }
};


//------------------------------------------------------

// approach 2, convert n to string
// convert all 2 powers to string
// sort and compare
/*
bool reorderedPowerOf2(int N) {
	string n = to_string(N);
	sort(begin(n), end(n));
	for(int i = 0, powOf2 = 1; i < 30; i++, powOf2 <<= 1){
		string pow2_str = to_string(powOf2);
		sort(begin(pow2_str), end(pow2_str));
		if(n == pow2_str) return true;  
	}
	return false;
}

*/