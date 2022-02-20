/*
K is 20
if nums[j] is 6
So we want (nums[i]*6) should be multiple of 20
Or we can say (nums[i]*2) should be multiple of 20

gcd(6 , 20) = 2 
Why??
bcz gcd is common here...  nums[i] should be multiple of k//(gcd k , nums[j])
Now , i want such nums[i] that have one of their divisor as k//(gcd k , nums[j])
*/

class Solution {
public:
    long long coutPairs(vector<int>& nums, int k) {
        unordered_map<int,int> factorCount;
        long long result =0;
     
        for (int i=0;i<nums.size(); i++){
            int factor = gcd(nums[i], k); // this is the "useful" part of nums[i]
            int missingFactor = k/factor; // what other factor is needed to form k
            
            if (missingFactor==1){ // if missingFactor is 1, the that means nums[i] can match with any previous index to form a pair, k*n %k == 0 bcz (factor == k), so iit will be divisible by k , irrespective of value of second element
                result += i;  // bcz 0 based indexing ( number of elements before currrent element )
            }else{ // if m is not 1, we can check if any previous index has the missing factor
                for (auto it=factorCount.begin(); it!=factorCount.end(); it++){
                    if ( it->first % missingFactor == 0){
                        result += it->second;
                    }
                }
            }
            // only add the "useful" factor part to the map
            factorCount[factor]++;
            
        }
        return result;
    }
};
