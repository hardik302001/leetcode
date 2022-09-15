class Solution:
    def findOriginalArray(self, l: List[int]) -> List[int]:
        l.sort()   # needed to easily keep track of big and small elements
        n = len(l)
        d = {}
        ans = []
        for i in l:
            f = 0
            if 2*i in d:
                if d[2*i]>0:
                    d[2*i]-=1
                    ans.append(i)
                    f = 1
            elif i%2==0:
                if i//2 in d:
                    if d[i//2]>0:
                        d[i//2]-=1
                        ans.append(i//2)
                        f = 1
            if not f:
                if i in d:
                    d[i]+=1
                else:
                    d[i] = 1

        return ans if len(ans)==len(l)//2 and len(l)%2==0 else []