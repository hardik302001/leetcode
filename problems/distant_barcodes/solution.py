# idea  same as : https://leetcode.com/problems/reorganize-string/submissions/

class Solution:
    def rearrangeBarcodes(self, bar: List[int]) -> List[int]:
        d = Counter()
        mostfreq = 0
        for i in bar:
            d[i]+=1
            if mostfreq<d[i]:
                mostfreq = d[i]
                el = i
     
        ans = [-1]*len(bar)
        i = 0
        
        while d[el]>0:
            ans[i] = el
            d[el]-=1
            i+=2
        
        
        for num in d:     
            while d[num]>0:
                if i>=len(bar): i = 1  # now it will follow odd indexes, i = 1, 3, 5 ...
                ans[i] = num
                d[num]-=1
                i+=2         # initially , this i will be continued from mostfreq charcter filling only, i = 0,2,
        return ans
                