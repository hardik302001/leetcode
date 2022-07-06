# SLIDING WINDOW
# FIND K IN FOR SIZE N, WINDOW

# courtesy NEETCODE CHANNEL YT!!
# search prob name there

'''
Idea
For the 1st operation, we can simply do s += s to append the whole string to the end.
then we make two different string with the same length by 01 and 10 alternative. for example: s = 11100
do s += s: s = 1110011100
goal 1: s1= 1010101010
goal 2: s2= 0101010101
finally, use sliding window（size n）to compare s to both s1 and s2.
why we can double s to fullfil the first operation, let's look at the same example s = 11100:`
double s: 1110011100
size n window: |11100|11100 ==> 1|11001|1100 ==> 11|10011|100 and so on, when we move one step of the sliding window, it is the same to append 1 more element from beginning.
Time complexity
Time O(N)
Space O(N) ==> O(1)


'''
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
            