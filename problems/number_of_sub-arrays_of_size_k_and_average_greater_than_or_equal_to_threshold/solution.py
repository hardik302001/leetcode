class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        ans = 0
        n = len(arr)
        l = 0
        s = 0
        
        for r in range(n):
            s += arr[r]
            
            if r-l+1>k:
                s-= arr[l]
                l+=1
                
            if r-l+1==k:
                if(s>= k*threshold):
                    ans+=1
        return ans