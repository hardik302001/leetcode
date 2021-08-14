#SLIDING WINDOW
#FIND KIN FOR SIZE N, WINDOW

#courtesy NEETCODE CHANNEL YT!!
#search prob name there
class Solution:
    def minFlips(self, s: str) -> int:
        n = len(s)
        s = s+ s                 #for first opertaion!
        alt1 = ""               #1010101....
        alt2 = ""               #0101010.....
        for i in range(2*n):
            if(i%2==0):
                alt1+="1"
                alt2+="0"
            else:
                alt1+="0"
                alt2+="1"
        res = n   #max pos ans
        l = 0
        diff1 = 0
        diff2 = 0
        
        for r in range(2*n):
            if s[r]!=alt1[r]:      #no of changes in final s wrt alt1
                diff1+=1
            if s[r]!=alt2[r]:      #no of changes in final s wrt alt2
                diff2+=1
            if (r-l+1)>n:          #as window size is more than n..we need to mmove left pointer and count the chnges
                if s[l]!=alt1[l]:
                    diff1-=1
                if s[l]!=alt2[l]:
                    diff2-=1
                l = l +1
            if (r-l+1)==n:         #window size is n,so calculat eresult
                res = min(res,diff1,diff2)
        return res
            