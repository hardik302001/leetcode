# SLIDING WINDOW : simple
# little bit simmilar idea: https://leetcode.com/problems/longest-repeating-character-replacement


class Solution:
    def maxConsecutiveAnswers(self, A: str, k: int) -> int:

        def findLen(A, n, k ,ch):    #we will replace ch, so we will take in acocunt count of ch
            maxlen = 1
            cnt = 0
            l = 0
            r = 0

            # traverse the whole string
            while r < n:
                if A[r] == ch:
                    cnt += 1

                while cnt > k:
                    if A[l] == ch:
                        cnt -= 1
                    l += 1
                maxlen = max(maxlen, r - l + 1)
                r += 1

            return maxlen

 
        
        n = len(A)
        ma = 1
        #max of both cases
        ma = max(ma, findLen(A, n, k , "T")) 
        ma = max(ma, findLen(A, n, k , "F"))
           
        return ma
        
        