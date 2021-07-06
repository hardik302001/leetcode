class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        d = {}
        n = len(arr)
        for i in arr:
            try:
                d[i]+=1
            except:
                d[i] = 1
        # print(d)
        d = sorted(d.items(), key=lambda item: item[1], reverse = True)
        # print(d)
        c = 0
        i = 0
        ans = 0
        while True:
            ans = ans + 1
            c = c + d[i][1]
            i = i + 1
            if c>=(n/2):
                break
        return ans
    
            
            
            
        