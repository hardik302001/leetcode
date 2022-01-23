class Solution:
    def numberOfArrays(self, diff: List[int], lb: int, ub: int) -> int:
        # let start point be x
        #keep x relative to 0 : x = x - x
        cur = 0
        arr = [cur]
        
        for i in diff:
            cur = cur + i
            arr.append(cur)
        
        
        mi = 100000000000
        ma = -100000000000
        
        
        '''
        now we got our original array , with 0 as starting element [ 0 , a, b, c, d ..]
        wrt original possible starting index arr would be [ x , x+a , x+b, x + c...]
        so now every element should be within range [lb, ub]
         lb <= x + alpha <= ub  , [ alpha is known]
         x >= lb-alpha    , max opssible x we can get from here for all arr[i]
         x <= ub-alpha    , min possible x we can get from here for all arr[i]
         
        So count of possible starting element will be from (max - min + 1)
        
        '''
        for i in range(len(arr)):
            ma = max(ma , lb- arr[i])
            mi = min(mi , ub - arr[i])
        if ma>mi:
            return 0
        else:
            return mi - ma + 1