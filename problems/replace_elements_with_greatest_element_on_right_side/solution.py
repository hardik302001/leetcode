class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        m = -1
     
        n = len(arr)
        ans = [0]*n
        for i in range(n-1, -1 , -1):
            ans[i] = m
            m = max(m , arr[i])
        return ans
            