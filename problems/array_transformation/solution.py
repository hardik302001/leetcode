class Solution:
    def transformArray(self, arr: List[int]) -> List[int]:
        while True:
            prev = deepcopy(arr)
            for i in range(1,len(arr)-1):
                arr[i] -= prev[i-1] < prev[i] > prev[i+1]
                arr[i] += prev[i-1] > prev[i] < prev[i+1]
            if prev == arr:
                return arr