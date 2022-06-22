class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        d = {}
        for i in words:
            if i in d:
                d[i]+=1
            else:
                d[i] =1 
        ans = 0
        ext = 0  # len of word that will come in middle
        # this word will be of form "xx"
        for cur in d:
            rev = cur[::-1]
            if rev!=cur:
                if rev in d and d[rev]>0:
                    cnt = min(d[cur], d[rev])
                    ans+= cnt*len(cur)*2
                    d[cur]-=cnt
                    d[rev]-=cnt
            else:
                cnt = d[cur]
                pairs = cnt//2
                ans+= pairs*2*len(cur)
                if cnt%2==1:
                    ext = max(ext , len(cur))  # maximum extra length possible
                    # the fact that ques has only 2 length word, so we can relace it by 2
                    
                d[cur] = 0
        ans+=ext
        
        return ans 