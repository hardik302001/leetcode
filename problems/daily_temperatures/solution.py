class Solution:
    def dailyTemperatures(self, t: List[int]) -> List[int]:
        
        n = len(t)
        ans = [0]*n
        st = []
        for i in range(n-1, -1,-1):
            cur = t[i]
            if(st):
                while st and t[st[-1]]<=cur:
                    st.pop()
            if(st):ans[i] = st[-1] - i
            st.append(i)
            # print(st)
        return ans
        

   