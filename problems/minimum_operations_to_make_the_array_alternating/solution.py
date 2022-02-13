class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        o = {}   # freq map for odd index elements
        e = {}   # freq map for even index elements
        n = len(nums)
        if n==1:
            return 0

        for i, v in enumerate(nums):
            if i&1: 
                if v in o:
                    o[v]+=1
                else:o[v]= 1
            else:
                if v in e:
                    e[v]+=1
                else:e[v]=1
        # sorting freq map on basis of freq in ascending order
        o = dict(sorted(o.items(), key=lambda item: item[1]))  
        e = dict(sorted(e.items(), key=lambda item: item[1]))
        
        besto = list(o.keys())[-1]   # highest freq key from odd map
        beste = list(e.keys())[-1]   # highest freq key from even map
        seo = list(o.keys())[-2] if len(o)>1 else 0  # second highest key from odd map, if len(o)>!
        see = list(e.keys())[-2] if len(e)>1 else 0  # second highest key from even map, if len(e)>1
        
        print(besto ,beste , seo ,  see)
        
        toto = (n)//2   # total odd index elements
        tote = (n+1)//2  # total even index elements
        
        if beste!=besto: # just greedily replace non highest eleemnts 
            return (toto - o[besto] + tote - e[beste])
        else:
            if seo==0 and see == 0:  # all elemenets equal in both maps, so we replace elements of odd map(bcz total odd count <= total even count)
                return toto
            elif seo==0:  # then we use second highest freq key from even map , as we cant replace odd key
                return (toto - o[besto] + tote - e[see])
            elif see ==0: # then we use second highest freq key from odd map , as we cant replace even key
                return (toto - o[seo] + tote - e[beste])
            else: # we consider minimum of both cases
                return min((toto - o[besto] + tote - e[see]) ,(toto - o[seo] + tote - e[beste]) )
                
        
        