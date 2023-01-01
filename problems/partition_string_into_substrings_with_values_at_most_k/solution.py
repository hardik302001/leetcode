class Solution:
    def minimumPartition(self, s: str, k: int) -> int:
        n = len(s)
        l = 1
        r = n+1
        for i in s:
            if int(i)>k:
                return -1
        
        c = 0
        cur = ''

        for i in range(n):
            t = cur + s[i]
            if ( int(t) >k):
                c+=1
                cur = ""
            cur +=s[i]

        if int(cur)>k:
            c+=2
        elif int(cur)<=k:
            c+=1
        return c