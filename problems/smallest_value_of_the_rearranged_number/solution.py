class Solution:
    def smallestNumber(self, n: int) -> int:
        if n>=0:
            l = list(str(n))
            # print(l)
            
            l.sort()
            i = 0
            while(i<len(l) and l[i]=="0"):
                i = i + 1
            if i==len(l):
                return "".join(l)
            mi = l[:i] + l[i+1:]
            mi = [l[i]] + mi
            return "".join(mi)
        else:
            n = abs(n)
            l = list(str(n))
            # print(l)
            
            l.sort(reverse = True)
            
            return "-" + "".join(l)
            