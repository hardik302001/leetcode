#coding decoded yt !



class Solution:
    def sortArrayByParityII(self, a):
        i = 0 # pointer for even misplaced (odd not at even index)
        j = 1 # pointer for odd misplaced  (even not at odd index)
        n = len(a) 
        
        # invariant: for every misplaced odd there is misplaced even
        # since there is just enough space for odds and evens

        while i < n and j < n:
            while i<n and a[i] % 2 == 0:
                i += 2
                
            while j<n and a[j] % 2 == 1:
                j += 2
                
            if i<n and j<n:
                a[i],a[j] = a[j],a[i]

        return a 