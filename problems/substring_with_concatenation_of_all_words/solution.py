#this time we are making nd equal to d, and starting from nd = {}
#this saves space and maybe time also
#somewhat better than taking flags
#see prev code for more info

#but still the concept of sliding window is not used..that is we are still making new dict every time, we should update the previous one only..but how we will do it...still thinking??
#see cpp code, this is based on sliding window concept..
#O(l*n*m)

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        
        res = []
        n = len(words)
        m = len(words[0])
        k = n*m
        l = len(s)
        d = {}
        for i in words:
            if i in d:
                d[i]+=1
            else:
                d[i]=1 
        
        
        for i in range(l-k+1):
            window = s[i:i+k]
            # print(window)
            f = 1
            nd = {}
            for j in range(0,k,m):
                p = window[j:j+m]
                if p in nd:
                    nd[p]+=1
                else:
                    nd[p] = 1
              
            if nd==d:
                res.append(i)
   
        return res
                