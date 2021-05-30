'''
Let's first find the mountain peak. As we do we this, we'll store values from mountain_arr.get() into a separate array to reference later. This algorithm should work under 100 get()'s without this step, but this is an extra safe-guard at the expense of memory.

Once we find the peak, which took O(log(n)) since it was a binary search, (just like https://leetcode.com/problems/peak-index-in-a-mountain-array/), we now perform at most 2 more binary searches.

First, search to the left of the peak for the target value. If we find it there, we're done. This search is binary, since from the start to the peak is a sorted array.

Next, if we didn't find the target to the left of the peak, search to the right of the peak. If we find it there, we're done. This search is also binary, but make sure you realize the listed is sorted descending.

If we didn't find it anywhere, return -1.
'''
class Solution:
    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:

        mt = mountain_arr   
        values = [None]*mt.length()     
        
        # Find the peak
        peak_i = self.findPeak(mt, values)
        
        # Check if the value is anywhere to the left of the peak
        left = self.find_val(values, mt, 0, peak_i, target, "L")
        
        if left != -1:
            return left
        
        # Check if the value is anywhere to the right of the peak
        right = self.find_val(values, mt, peak_i, mt.length()-1, target, "R")
        
        if right != -1:
            return right
        
        return -1
    
    # Binary Search for target value
    def find_val(self, values, mt, l, r, target, mt_side):

        middle = (l + r + 1)//2

        if l > r:
            return -1
        
        if values[middle] is None:
            values[middle] = mt.get(middle)
        
        if l == r:

            if values[l] != target:
                return -1
            else:
                return middle
   
            
        # If we're bigger than the target
        if values[middle] > target:
            
            if mt_side == "L":
                r = middle-1
                return self.find_val(values, mt, l, r, target, mt_side)
            else:
                l = middle+1
                return self.find_val(values, mt, l, r, target, mt_side)                
        
        # We found the taget
        elif values[middle] == target:
            return middle
        
        # We're smaller than the target
        else:
            if mt_side == "L":
                l = middle+1
                return self.find_val(values, mt, l, r, target, mt_side)
            else:
                r = middle-1
                return self.find_val(values, mt, l, r, target, mt_side)                    

    # Find the peak of the mountain
    def findPeak(self, mt, values) -> int:
        
        l = 0
        r = mt.length()-1
        peak_i = (l + r + 1)//2
        
        while True:
            
            # As we search for the peak, store the values
            # From the mountain in an array for later reference
            # This reduces the later calls to mountain_arr
            if values[peak_i] is None:
                values[peak_i] = mt.get(peak_i)

            if values[peak_i-1] is None:
                values[peak_i-1] = mt.get(peak_i-1)

            if values[peak_i+1] is None:
                values[peak_i+1] = mt.get(peak_i+1)

            # Found the peak
            if values[peak_i-1] < values[peak_i] and values[peak_i] > values[peak_i+1]:
                return peak_i

            else:
                # To the left of the peak
                if values[peak_i-1] < values[peak_i] and values[peak_i] < values[peak_i+1]:
                    l = peak_i
                    peak_i = (l + r + 1)//2

                # To the right of the peak
                else:
                    r = peak_i
                    peak_i = (l + r + 1)//2   