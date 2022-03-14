/*
// 1. Hashmap will take extra space O(n)



// 2. bcz array is already sroted, so we directly compae it with prev element 
// TC: O(n)
// SC: O(1)

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int count = 0;
        int n= arr.size();
        int prev = -1;
        int req = n / 4;
        for(int i : arr) {
            if(i == prev) {
                count++;
            }
            else {
                prev = i;
                count = 1;
            }
            if(count > req) {
                return i;
            }
        }
        return -1;
    }
};
*/
    
// 3.
// TC: O(n)
// SC: O(1)

// class Solution {
// public:
// 	int findSpecialInteger(vector<int>& arr) {
// 		for(int i = 0; i <= (arr.size() * 3) / 4; i++){
// 			if(arr[i] == arr[i + arr.size() / 4]){
// 				return arr[i];
// 			}
// 		}
// 		return arr[0];
// 	}
// };



// 4. Binary searcg 
// Time complexity: O(logn)
// Space complexity: O(1)
// Because it's guaranteed that only one number will appear more than 25% times, that number will definitely appear at one of the three positions in the array: quarter, half, and three quarters. We see them as candidates, and then using binary search to check each of them.



class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int sz = arr.size();
        int limit = sz/4;
        vector<int> candidates = {arr[sz/4], arr[sz/2], arr[sz*3/4]};
        for (auto cand : candidates) {
            int  start = lower_bound(arr.begin(),arr.end(),cand)-arr.begin();
            int  end = upper_bound(arr.begin(),arr.end(),cand)-arr.begin();
            
            // freq > limit then return cut value
            if(end-start > limit)return cand;
        }
        return -1;
    }
};

