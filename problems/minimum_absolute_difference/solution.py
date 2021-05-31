class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        ma = min(arr[i] - arr[i-1] for i in range(1, len(arr)))
        results = [[arr[i-1], arr[i]] for i in range(1, len(arr)) if arr[i] - arr[i-1] == ma]
        return results