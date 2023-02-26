class Solution:
    def minimumSwaps(self, nums: List[int]) -> int:
        mi = min(nums)
        ma = max(nums)
        f = 0
        n = len(nums)
        miind = -1
        maind = -1
        for i , x in enumerate(nums):
            if x==mi and not f:
                miind = i
                f = 1
            
            if x==ma:
                maind = i
        print(miind , maind)
        if miind < maind:
            return miind + n - 1 - maind
        elif miind==maind:
            return 0
        else:
            return ( miind - maind ) + (miind-1) + (n - 1 - miind)
        
        
        '''
        Total = 7 steps
        3 4 2 5 3 1 8
        3 4 2 3 5 1 8
        3 4 2 3 1 5 8
                _ _ 
        2 swaps done for interchange
        5 is now at position of miind , and 1 is now at position miind -1
        
        Now send 1 to position 0
        So , we need to do miind -1 swaps
        
        Now send 5 to position n-1
        it will take n-1-miind swaps
   
        '''
        
        