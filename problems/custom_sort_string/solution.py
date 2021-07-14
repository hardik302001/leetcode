class Solution:
    def customSortString(self, order: str, st: str) -> str:
        d = {}
        for i in st:
            if i in d:
                d[i]+=1
            else:
                d[i] = 1
        neword = ""
        for i in order:
            if i in d:
                neword = neword + i
        #taking common 
                
        ans = ""
        for i in neword:
            ans = ans + i*d[i]
            d[i] = 0
        #taking all occurence of common first..
            
        for i in d:
            ans = ans + i*d[i]
        #then occurence of left ones from str
        
        
        return ans
            