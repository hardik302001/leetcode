// https://leetcode.com/problems/single-element-in-a-sorted-array/discuss/628111/C%2B%2B-Solution-O(logn)-with-detailed-explanation


class Solution {
public:

    int singleNonDuplicate(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<r)
        {
            int m=l+(r-l)/2;         
            bool even_length=(r-m)%2==0;    //can be both even and odd acordingly (number of lemeents between right end and elemenst after mid (r-mid== excluding mid, elements tilll end...))
            if(nums[m]==nums[m+1])
            {
                if(even_length)
                    l=m+2;
                else
                    r=m-1;
            }
            else if(nums[m]==nums[m-1])
            {
                if(even_length)
                    r=m-2;
                else
                    l=m+1;
            }
            else
                return nums[m];
        }
        return nums[l];
    }


};