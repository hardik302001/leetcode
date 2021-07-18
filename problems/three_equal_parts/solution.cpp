

class Solution {
public:
    //https://leetcode.com/problems/three-equal-parts/discuss/183922/C++-O(n)-time-O(1)-space-12-ms-with-explanation-and-comments
    vector<int> threeEqualParts(vector<int>& A) {

        int ones = 0;
        for(int c: A)
            if(c == 1)                  
                ones++;
								
	    // If no 1 is found, that means we can return ans as {0, size-1}
        if(ones == 0)      
            return {0, (int)A.size()-1};
        
        //Each prtition must have equal number of ones
        if(ones % 3 != 0)            
            return {-1, -1};
						
        // find size of each partition
        int k = ones/3;

        // find the first 1 in EACH PARITION 
        int partOnes = 0; //partition Ones
        vector<int> pos;
        for(int i=0;i<A.size(); i++)
        {
            if(A[i]==1) 
                partOnes++;
            
            if(A[i]==1 && partOnes == 1)
                pos.push_back(i);
            if(partOnes==k)
                partOnes = 0;
                
        }
        
        int start = pos[0], mid = pos[1], end = pos[2];
        
        //Zeros are already skipped in the above search
        // Match all values in EACH PARTITION
        while(end< A.size() && A[start] == A[mid] && A[mid] == A[end])
        {
            start++; mid++; end++;
        }
        
        if (end == A.size())
            return {start-1,mid};
        
        return  {-1,-1};
    }
};