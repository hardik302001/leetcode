class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        
        triplests = []
        ans = 0
        for i in range(len(arr)):
            for j in range(i+1, len(arr)):
                if abs(arr[j] - arr[i]) <= a:
                    for k in range(j+1, len(arr)):
                        if (abs(arr[k] - arr[j]) <= b) and (abs(arr[i] - arr[k]) <= c):
                            ans += 1

        return ans