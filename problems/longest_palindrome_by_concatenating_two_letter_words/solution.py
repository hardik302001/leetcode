class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        d = {}
        samee = []
        sameo = []
        diff = []
        
        ans = 0
        for i in words:
            if i in d:
                d[i]+=1
            else:
                d[i] = 1
        f = 0
        for i in d:
            if i[::-1] in d and d[i[::-1]]>0:
                if i!=i[::-1]:
                    p = min(d[i], d[i[::-1]])
                    ans = ans + 4*p     
                    d[i]= d[i] - p
                    d[i[::-1]]= d[i[::-1] ]- p
                else:
                    if d[i]&1:
                        sameo.append(d[i])
                    else:
                        ans = ans + 2*d[i]
        # print(sameo)
        for i in sameo:
            f = 1
            ans = ans + (i-1)*2
            
        if f:
            ans = ans + 2
        
                    
        return ans
            