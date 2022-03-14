// preprocess and check if sum is possible



#define ll long long 




class Solution {
public:
    
    int findMinFibonacciNumbers(int k) {
        vector<ll> fib;
        fib.push_back(1);
        fib.push_back(1);
        
        // generate fibs less than equal to k
        for(int i=2;;i++)
        {
            if( (fib[i-1]+fib[i-2]) > k)
                break;
            fib.push_back(fib[i-1]+fib[i-2]);
        }
        int c = 0;
        int j  = fib.size()-1;
        
        // select greedily and keep subtracting till 0
        while(true){
            ll x = fib[j];
            c += k/x;
            k%=x;
            if(k==0)
                break;
            j--;
        
        }
        return c;
        
    }
};