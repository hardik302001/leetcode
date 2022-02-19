// https://leetcode.com/problems/minimize-deviation-in-array/discuss/1781805/A-very-very-Highly-Detailed-EXPLANATION

/*
APPROACH 1 USING PRIORITY QUEUE

EXPLANATION

1. To decrease the deviation either increase the minn or decrease the maxx.
2. Now, Make every number as maximum as possible to eliminate one operation(increase the minn)
3. since every element is as maximum as possible , you can not increase any number further
4. Now we are left with just one operation decrease the maxx
5. So perform this operation as many times as u can and keep track of the min_deviation
Time Complexity: O(nlog(m)log(n))
Space Complexity: O(n)

*/
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN, mn = INT_MAX;
                
        priority_queue<int> pq;
        // Inserting into Priority queue (Max Heap) and try to decrease as much we can
        
        // Increasing all elements to as maximum as it can and tranck the minimum,
        // number and also the resutl
        for(int i = 0; i<n; ++i)
        {
            if((nums[i]%2) != 0)    // multiplication by 2 if nums[i] is odd
                nums[i] *= 2;   // maximising all odd numbers

        
            mx = max(mx,nums[i]);
            mn = min(mn,nums[i]);
            pq.push(nums[i]);
        }
        
        int min_deviation = mx - mn;

        while((pq.top()) % 2 == 0)
        {
            int top = pq.top();
            pq.pop(); // popped the top element
            
            min_deviation = min(min_deviation, top - mn);
            top /= 2;
            mn = min(mn, top);  // updating min
            pq.push(top);   // pushing again the top as we have to minimize the max
        }
        
        min_deviation = min(min_deviation, pq.top() - mn);
        
        // we are returning mx - mn
        
        return min_deviation;
    }
};
