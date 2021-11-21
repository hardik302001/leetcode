#using first and last elements
class Solution:
    def maxDistance(self, arr: List[int]) -> int:
        res = 0
        n = len(arr)
		
        for i in range(n): 
            if arr[i] != arr[0]:  #first
                res = max(res, i)
            if arr[i] != arr[-1]:  #last
                res = max(res, n-i-1)
			
        return res 