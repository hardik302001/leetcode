# same as leetcode 2615

from collections import defaultdict
 
class Solution:
    class pair:
        def __init__(self, count,prevIndex):
            self.count = count;
            self.prevIndex = prevIndex;
    def getDistances(self, arr: List[int]) -> List[int]:

        n = len(arr)
   
        map = {};
  
        # Initialize 2 arrays left[]
        # and right[] of size N
        left = [0 for i in range(n)];
        right = [0 for i in range(n)];
  
        # Traverse the given array
        for i in range(n):
  
            # If arr[i] is present in the Map
            if (arr[i] not in map):
  
                # Update left[i] to 0
                # and update the value
                # of arr[i] in map
                left[i] = 0;
                map[arr[i]] =  self.pair(1, i);
             
            # Otherwise, get the value from
            # the map and update left[i]
            else:
                tmp = map[arr[i]];
                left[i] = (tmp.count) * (i - tmp.prevIndex) + left[tmp.prevIndex]
                map[arr[i]] = self.pair( tmp.count + 1, i);
             
  
        # Clear the map to calculate right[] array
        map.clear();
  
        # Traverse the array arr[] in reverse
        for i in range (n - 1, -1, -1):
  
            # If arr[i] is present in theMap
            if (arr[i] not in map):
  
                # Update right[i] to 0
                # and update the value
                # of arr[i] in the Map
                right[i] = 0;
                map[arr[i]] =  self.pair(1, i);
     
            # Otherwise get the value from
            # the map and update right[i]
            else:
  
                tmp = map[arr[i]];
                right[i] = (tmp.count) * (abs(i - tmp.prevIndex)) + right[tmp.prevIndex];
  
                map[arr[i]] =  self.pair(tmp.count + 1, i);
         
        # Iterate in the range [0, N-1]
        # and print the sum of left[i]
        # and right[i] as the result
        ans = []
        for i in range(n):
            ans.append(left[i] + right[i])
        return ans