class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        d = {}
        m = 10000000
        n = len(arr)
        arr.sort()
        for i in range(1, n):
            dif = abs(arr[i]-arr[i-1])
            m = min(m, dif)
            if dif in d:
                d[dif].append([arr[i-1],arr[i]])
            else:
                d[dif] = [[arr[i-1],arr[i]]]
                          
        
        return d[m]