# Priority:
# 1. Lexographic maximum
# 2. maximum length 

# O(n) , if we do not sort and chcek all chars from 'z to a' in backward direction 

class Solution:
    def repeatLimitedString(self, s: str, k: int) -> str:
        ans = ""
        n = len(s)
        d = {}
        for i in s:
            if i in d:
                d[i]+=1
            else:
                d[i] = 1
        p =list(d.keys())
        p.sort(reverse = True)
        for i in range(len(p)):
            while d[p[i]]>0:
                need = min(k , d[p[i]])
                d[p[i]]-=need
                temp = p[i]*need
                ans = ans + temp
                
                
                if d[p[i]]>0:
                    f = 0         # flag for next less charcter
                    for j in range(i+1, len(p)):
                        if d[p[j]]>0:
                            ans = ans + p[j]
                            d[p[j]]-=1
                            f = 1
                            break
                    if not f:  # if we do not get any less char to add , we need to stop here only!
                        return ans
              
        return ans