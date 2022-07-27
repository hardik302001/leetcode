'''
really good ques, 
see soln below, 
but why tf we ignored  maxsize??
bcz all substrings of size greater than minsize and <= maxsize , will eventually have the substring of size minsize
so we explicitly need not worry about substrings of size greater than minsize and <= maxsize

'''


class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        d = {}
        n = len(s)
        fre = [0]*26
        l = 0
        uni = 0
        for r in range(n):
            cur = s[r]
            fre[ord(cur)-ord('a')]+=1
            if fre[ord(cur)-ord('a')]==1:     uni+=1
            
            while uni>maxLetters or minSize < (r-l+1):
                back = s[l]
                fre[ord(back)-ord('a')]-=1
                if fre[ord(back)-ord('a')]==0: uni-=1
                l+=1
                
            if minSize==(r-l+1):
                if s[l:r+1] in d:
                    d[s[l:r+1]]+=1
                else:
                    d[s[l:r+1]] =1 
                    
                    
        ans = 0
        for i in d:
            ans = max(ans , d[i])
        return ans