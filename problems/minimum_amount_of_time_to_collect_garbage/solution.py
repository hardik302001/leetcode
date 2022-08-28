class Solution:
    def garbageCollection(self, garbage: List[str], travel: List[int]) -> int:
        m = 0
        g = 0
        p = 0
        lm = -1
        lg = -1
        lp = -1
    
        for i , v in enumerate(garbage):
            if 'G' in v:
                lg = i
            if 'P' in v:
                lp = i
            if 'M' in v:
                lm = i
         
        for i,v in enumerate(garbage):
            if i <= lg:
                g += v.count('G')
                if not ( i==(len(garbage)) or i==lg ): g += travel[i]
                
            if i <= lm:
                m += v.count('M')
                if not ( i==(len(garbage)) or i==lm ): m += travel[i]
            if i <= lp:
                p += v.count('P')
                if not ( i==(len(garbage)) or i==lp ): p += travel[i]
            
        return p + m + g
                
            