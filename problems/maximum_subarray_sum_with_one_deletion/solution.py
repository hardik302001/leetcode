class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        ans = arr[0]   # bcz subarray needs to be non-empty after deleting one elem,so we need to keep first element !
        n = len(arr)
        notDelete = [0]*n  # notDelete[i] tells maximum subarray sum , if non of element is delteed
        notDelete[0] = arr[0]
        delete = [0]*n  # delete[i] tells maximum subarray sum , if one of element is deleted
        #delete[0] = 0 , bcz if we delete first element then max subaray sum till index 0 , is 0
        
        
        for i in range(1,n):  # start from first index
            
            # first update notDelete[i] , bcz we need it in calculating delete[i]... 
            
            notDelete[i] = max(notDelete[i-1] + arr[i] , arr[i]) # similar to kadane, 
            delete[i] = max(delete[i-1] + arr[i] , notDelete[i-1]) # either add current element to delete[i-1] , bcz we have already deleted one element, or delete current element and add notDelete[i-1]..
            
            m = max(delete[i] , notDelete[i])  # bcz we can choose a subarray and optionally delete one element from it ( so we choose max from delete array and notdelete array)
            ans = max(ans, m)
        return ans