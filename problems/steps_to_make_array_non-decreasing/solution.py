'''

Scan from right to left, maintain an increasing stack.
For i<j and nums[i]>nums[j], the number of rounds for nums[i] to remove nums[j] is:
1. If nums[j] takes 3 rounds to remove all smaller numbers on its right, then it will also take nums[i] same 3 rounds to remove nums[j], not 1 round.
2. If nums[j] has nothing to remove on its right side, then nums[i] will take at least 1 round to remove nums[j].


'''
class Solution:
    def totalSteps(self, arr: List[int]) -> int:
        n = len(arr)
        st = []
        m = 0       
        c = 0
        for i in range(n-1,-1,-1): 
            c = 0  
            while len(st) and st[-1][0]<arr[i]:
                num , prev = st.pop()
                c = max( c+1 , prev)
                
            m = max( m , c)
            st.append([arr[i], c])

        return m