class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        d = Counter()
        for dom in cpdomains:
            p = dom.split()
            c = int(p[0])
            l = p[1].split(".")
            
            cur = l[-1]
            d[cur]+=c
            n = len(l)
            for x in range(n-2, -1 , -1):
                cur = l[x]+'.'+cur
                d[cur]+=c
        p = []
        for i in d:
            p.append([str(d[i])," ", i])
        
        ans = []
        for i in p:
            ans.append("".join(i))
     
        return ans
        