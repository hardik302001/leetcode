#sliding window 
# see stack soln in cpp


class Solution:
    def longestBeautifulSubstring(self, word: str) -> int:
        next = 'a'
        ans = 0
        l = 0   #l==r always, bcz then we will fix l there and move r
        n = len(word)
        for r in range(n):
            if word[r] in next:
                if word[r] =='a':
                    next = 'ae'
                elif word[r] =='e':
                    next = 'ei'
                elif word[r] == 'i':
                    next = 'io'
                elif word[r] == 'o':
                    next = 'ou'
                elif word[r]=='u':
                    next = 'u'
                    ans = max(ans, r-l+1)   
            else:
                if word[r]=='a':     # 'aeioua', so after 'u', we wanted 'u' but we got 'a', so we would consider this 'a' as start of our next segment, so l= r, and next = 'ae', bcz we already got 'a'
                    next='ae'
                    l = r    #we got our segment, so we fixed l
                else:                # else if that is not the case it means, we want 'a' as beginning symbol of our segment and we did not got that, so next = 'a' and l = r+1..we dont know if the next char would be our start of new segment or not..so till then we would update l = r+1, so after this iteration end r would increment by 1, and now we have l==r!
                    next = 'a'
                    l = r+1
                
                
                
        return ans
                