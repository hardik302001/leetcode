# sliding window minimise (pref + suf) ~ maximise window (without failing any of 3 condition for pref and suf)


class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        d = Counter(s)
        ma = 0
        aa = 0
        n = len(s)
        bb = 0
        cc = 0
        l = 0
        maaa = {}
        
        for i in ['a','b','c']:
            if d[i]<k:
                return -1    
       
        for r in range(n):
            if s[r]=='a': aa+=1
            elif s[r]=='b': bb+=1
            else:  cc+=1
            
            while (d['a']-aa <k or d['b']-bb<k or d['c']-cc<k):
               
                if s[l]=='a': aa-=1
                elif s[l]=='b': bb-=1
                else:  cc-=1
                l+=1
          
            ma = max(ma , r-l+1 )   

        return n - ma