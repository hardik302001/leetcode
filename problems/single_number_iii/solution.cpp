//Time : O(n)
//Space : O(1)
// courtesy: https://leetcode.com/problems/single-number-iii/discuss/1561847/C%2B%2B-EASY-INTUITIVE-SOL-oror-BIT-MANIPULATION-oror-O(N)-time-and-O(1)-Space-Complexity



class Solution {
public:
    
    // Utility function that returns MSB of a number in O(1) time (basically a mask of MSB)
    
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int>res;
        int bucket1= 0;
        int bucket2=0;
        long long int xr = 0;
        
		//Calculate xor of every number so that xr will have (x^y)
        for(int i{}; i<n; ++i) 
            xr = xr ^ nums[i];
        cout<<xr<<endl;
		
        
        // Compute rightmost set bit of xr, gives us the ith bit we need as a mask
        int mask = rightmost_setbit(xr); 
        cout<<mask<<endl;
        
        
		// Fill our buckets according to our intuition mentioned in above steps
        for(int i= 0; i<n; ++i){
            
            if(mask & nums[i])
                bucket1 ^= nums[i];
            
            else
                bucket2 ^= nums[i];
        }
        
		// bucket1 and bucket2 will contain x and y
        res.push_back(bucket1);
        res.push_back(bucket2);
        
        return res;
    }
    
    

 
    int rightmost_setbit(int num)
    {
      if(num==0)// for num==0 there is zero set bit
      {  return 0;
      }
      else
      {
        int temp;
        int pos = 1;
        // counting the position of first set bit
        for (int i = 0; i < 32; i++) {
            if (!(num & (1 << i)))
                pos++;
            else{
                temp = i;
                break;
            }
        }
        return (1<< temp);        //we are reutning the number
      }
    }
};