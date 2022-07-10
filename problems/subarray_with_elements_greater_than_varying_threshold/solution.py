# we need something like sliding window minimum
# not exactly that, but something like that, we need to work with minimum..
# if minimum is greater than  threshold , then that subarray will work

# approach = MONOTONIC STACK, pse, nse
# conisder current element to be minimum and consider length of maximum possible subarray , and see if it satifies..


class Solution:
    def validSubarraySize(self, arr: List[int], threshold: int) -> int:
        n = len(arr)
        
        
        nge = [-1]*n
        pge = [-1]*n
        nse = [-1]*n
        pse = [-1]*n
        
        st = []
        for i in range(n):
            while len(st) and arr[st[-1]] > arr[i]:
                nse[st[-1]] = i
                st.pop()   
            st.append(i)
            
        st = []
        for i in range(n-1,-1,-1):
            while len(st) and arr[st[-1]] >= arr[i]:
                pse[st[-1]] = i
                st.pop()
            st.append(i)
            
        for i in range(n):
            if pse[i]==-1:
                left = i            # number of elements on left to current
            else:
                left = (i-pse[i]-1)
            if nse[i]==-1:
                right = n-i-1       # number of elements on right to current
            else:
                right = (nse[i]-i-1)
            
            length = left + 1 + right

            p = threshold/length
              
            if p<arr[i]:
                print(p , arr[i], length)
                return length
            
            
        return -1