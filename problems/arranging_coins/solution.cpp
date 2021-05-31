class Solution {
public:
    int arrangeCoins(int n) {
        long long start = 0;
        long long end = n;
        //not that optimised..prevous soln is much  more optmised
        
        while(start<=end)
        {
            long long mid = (start+end)/2;
            
            if((mid*(mid+1))/2==n)
                return mid;
            
            if((mid*(mid+1))/2>n)
                end = mid-1;
            else
                start = mid+1;
        }
        
        return start-1;
        
    
    }
};