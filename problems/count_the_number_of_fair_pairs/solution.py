# see cpp
class Solution:
    def countFairPairs(self, arr: List[int], L: int, R: int) -> int:
        arr.sort()
        N = len(arr)
        left = 0
      
        ans = 0
        count = 0
  

        for right in range(N):
            it1 = bisect_left(arr, L - arr[right])
            s = it1
            it2 = bisect_right(arr, R - arr[right])
            it2 -= 1
            e = it2
            
            e = min(e, right - 1)
            if (e - s >= 0):
                ans += (e - s + 1)
            right -= 1
            left +=1

        return ans