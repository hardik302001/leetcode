class Solution:
    def trimMean(self, arr: List[int]) -> float:
        n = len(arr)
        rem = n//20
        arr.sort()
        arr = arr[rem: n-rem]
        
        return sum(arr)/(n-2*rem)