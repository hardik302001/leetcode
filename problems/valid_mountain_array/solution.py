class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        n = len(arr)
        if n<3:
            return False
        j = 0
        for i in range(n-1):
            if arr[i]<arr[i+1]:
                continue
            elif arr[i]==arr[i+1]:
                return False
            else:
                j = i
                break
        if j==0:return False   #we need inc then decreasing
        for i in range(j,n-1):
            if arr[i]>arr[i+1]:
                continue
            else:
                return False
        if arr[-1]<arr[-2]:
            return True
        else:
            return False