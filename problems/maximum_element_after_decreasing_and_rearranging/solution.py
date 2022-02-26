class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        m = 1
        arr.sort()
        n = len(arr)
        
        arr[0] = 1
        for i in range(1,n):
            arr[i] = min(arr[i-1]+1, arr[i])
            m = max(m , arr[i])
        return m