class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        n = len(tokens)
        if n==1:
            return 1 if tokens[0]<=power else 0
        
        tokens.sort()
        i = 0
        j = n-1
        ans = 0
        c = 0
        
        
        
        while i<=j:
            if tokens[i]<=power:
                power-=tokens[i]
                i+=1
                c+=1
            else:
                if c:
                    power+=tokens[j]
                    c-=1
                    j-=1
                else:
                    break
            ans = max(ans,c)
                        
        return ans