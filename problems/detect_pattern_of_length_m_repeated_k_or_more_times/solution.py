
class Solution:
    def containsPattern(self, arr: List[int], m: int, k: int) -> bool:
        i = 0
        n = len(arr)
        while i < n:
            p = arr[i:i+m]
            if p * k == arr[i:i+m*k]:
                return True

            i += 1

        return False