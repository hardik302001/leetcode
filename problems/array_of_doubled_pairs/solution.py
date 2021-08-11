class Solution:
    def canReorderDoubled(self, arr: List[int]) -> bool:
        n = len(arr)
        ans = []
        
        d = {}
        p = sorted(arr,key = lambda x: abs(x), reverse = True)
        # print(p)
        #arr = [4,2,-2,-4]  
        #after sorting we have p = [4,-4,2,-2]   sorting on basis of absolute value!
        
        for x in p:
            if x*2 in d and d[x*2]>0:

#we need d[x*2]>0 bcz suppose we found d[x*2] before, we added it in d, now we found such x, for which d[x*2] #exists, so we we will do -1 fro both d[x] and d[x*2], so now d[x*2] = 0 BUT it exists now also! by existing we #mean we have that key in dictionary irrspective of whatever value it have! But actually we want to do d[x*2]-=1 #only when we have d[x*2]>0!

#for more info, try debugging sample tc 1
                
                d[x*2]-=1
                ans.append(x)     #pushing pair in ans array!
                ans.append(x*2)
            else:
                if x in d:
                    d[x]+=1
                else:
                    d[x]=1
        print(d)
        return sum(d.values())==0
        #if we want to print the final answer, the result array after reordering, we can get that in  ans array