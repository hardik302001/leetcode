class Solution:
    def platesBetweenCandles(self, s: str, queries: List[List[int]]) -> List[int]:
        n=len(s)
        pre=[0]*n
        left=[-1]*n          #indexes of nearest left candle
        right=[n+1]*n        #indexs of nearest right cadle
        c=-1
        for i in range(n):
            if s[i]=="|":
                c=i
                left[i]=c
            else:
                left[i]=c
        c=n+1
        for i in range(n-1,-1,-1):
            if s[i]=="|":
                c=i
                right[i]=c
            else:
                right[i]=c
        # print(left)
        # print(right)
        c=0
        star=[0]*n          #count of stars tille very index i (only stars no candles)
        for i in range(n):
            if s[i]=="*":
                c+=1
                star[i]=c
            else:
                star[i]=star[i-1]
        # print(star)
        
        
        res=[]
        for st,end in queries:
            sti=right[st]      #nearest left candle from that (after or on that ) starting index
            endi=left[end]     #nearest right candle from that (before or on that ) end index
            # print(sti,endi)
            if sti==endi or sti>end or endi<st: #if only single candle segment or out of bound segments then 0
                res.append(0)
            else:
                res.append(star[endi] - star[sti])   #else find count of stars (only stars , no candlles, so we explictly made star prefix array)
        return res