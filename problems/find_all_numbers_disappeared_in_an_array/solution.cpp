//very similar to : https://leetcode.com/problems/find-all-duplicates-in-an-array/


/*
Since, each element in the array is in range [1,n], it means we can use array elements as index for the same array.

So the idea is to use array element as indexes, and mark those indexes, somehow, so we know, which all indexes are present in the array.

In the end, unmarked indexes will indicate that these elements are missing in the array.
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        
        for( int i=0; i < nums.size(); i++)
        {
            int n = abs(nums[i]); 
            if(nums[n-1] > 0)
                nums[n-1] = -nums[n-1]; // marking -ve
        }
        for( int i=0; i < nums.size(); i++)
        {
            if(nums[i]>0)
                res.push_back(i+1);
        }
        return res;
    }
};