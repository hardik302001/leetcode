class Solution:
    def platesBetweenCandles(self, s: str, queries: List[List[int]]) -> List[int]:
        n=len(s)
        pre=[0]*n
        left=[-1]*n
        right=[n+1]*n
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
            
        c=0
        star=[0]*n
        for i in range(n):
            if s[i]=="*":
                c+=1
                star[i]=c
            else:
                star[i]=star[i-1]
        res=[]
        for st,end in queries:
            st1=right[st]
            end1=left[end]
            if st1==end1 or st1>end or end1<st1:
                res.append(0)
            else:
                res.append(star[end1]-star[st1])
        return res