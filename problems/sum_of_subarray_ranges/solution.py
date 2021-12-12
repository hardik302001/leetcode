class Solution:
    def subArrayRanges(self, arr: List[int]) -> int:
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
            
        st = []
        for i in range(n):
            while len(st) and arr[st[-1]] < arr[i]:
                nge[st[-1]] = i
                st.pop()   
            st.append(i)
            
        st = []
        for i in range(n-1,-1,-1): 
            while len(st) and arr[st[-1]] <= arr[i]:
                pge[st[-1]] = i
                st.pop()
            st.append(i)
        
        minans = 0
        
        for i in range(n):
            if pse[i]== -1:
                left_diff = i - 0
            else:
                left_diff = (i - pse[i]) - 1
                
            if nse[i]== -1:
                right_diff = n-1 - i
            else:
                right_diff = (nse[i] - i) - 1
            
            # print(left_diff, right_diff)
            minans = minans + arr[i]* (left_diff +1)*( right_diff+1)
        
        maxans = 0
        
        for i in range(n):
            if pge[i]== -1:
                left_diff = i - 0
            else:
                left_diff = (i - pge[i]) - 1
                
            if nge[i]== -1:
                right_diff = n-1 - i
            else:
                right_diff = (nge[i] - i) - 1
            
            # print(left_diff, right_diff)
            maxans = maxans + arr[i]* (left_diff +1)*( right_diff+1)
            
        return maxans - minans