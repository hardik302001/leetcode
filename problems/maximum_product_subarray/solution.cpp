// also see: https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/

/*

Simplest case. Consider this array [1,2,3,-4,5,6]. We can think of -4 as dividing the array into 2 halves, [1,2,3] and [5,6]. The forward traversal yields the max as 6, while the reverse traversal yields 30.
Say the array has even number of negative numbers eg. [1,2,-3,-4,5,6]. Both forward and reverse traversals yield the same result, so it doesnt matter.
Say the array has multiple odd number of negative integers. eg. [1,2,-3,-4,-5, 6]. We can think of the "last" negative number in each traversal breaks the array to 2 halves. In this case , the max array in forward traversal is the maximum of ([1,2,-3,-4] and [6]) which is 24. In the reverse, the split is delimited by -3. So the max subarrray is teh maximum of ([6,-5,-4] and [2])

Hence, in the end, its all about the presence of odd or even number of negative integers.
In case of even, the product is always positive. 
In case of odd, the max product is limited by the last negative integer in each traversal[ basically the corner negative integer ] .(because we would take even count of negative integers on left/right side and the one last left would be the odd one out(corner negative) and we would skip it as considering it would give negative product!). 

*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int n = nums.size();
        
        //forward traversal
        int p =  1;
        for(int i = 0;i<n;i++){
            if(nums[i]==0){   //we need to start again , and skip 0, bcz we need subarray and it will make product 0
                p = 1;
                ans = max(ans, 0);
            }
            else{
                p = p*nums[i];
                ans = max(ans, p);
            }
        }   
        
        //backward traversal
        p =  1;
        for(int i = n-1;i>=0;i--){
            if(nums[i]==0){
                p = 1;
                ans = max(ans, 0);
            }
            else{
                p = p*nums[i];
                ans = max(ans, p);
            }
            
        }
        
        return ans;
    }
};