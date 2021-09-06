class Solution:
    def numberOfWeakCharacters(self, p: List[List[int]]) -> int:
        p.sort(key = lambda x: (x[0],x[1]))
        l = []        # group of defeences, having diffrenet attcks 
        a = p[0][0]
        ll = []
        for i in p:
            if i[0]==a:
                ll.append(i[1])
            else:
                l.append(ll)
                a = i[0]
                ll = []
                ll.append(i[1])
        l.append(ll)
        
        print(l)
        ans = 0
        allmax = 0               #keep track of max of all elemnts from end..bcz list is reveersed
        
        for listi in l[::-1]:
            m = allmax       #m is max of all elements in listi, bcz we cant have eleemnts from same list .
                                #we need a seperate variable to keep track of both maxxes, allmax is maximum of all eleemnets, it will be considered for all listi that occur after until we have calculated allmax
                
                #m is to get max of that list, so that after completeting that listi we can updatte allmax.
            
            for i in listi:
                if i<m:
                    ans = ans + 1
                m = max(i,m)
            allmax = max(allmax,m)
        return ans
            