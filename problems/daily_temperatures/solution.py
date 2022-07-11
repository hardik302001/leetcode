# nge

class Solution:
    def dailyTemperatures(self, arr: List[int]) -> List[int]:
        n = len(arr)
        nge = [-1]*n
        st = []
        for i in range(n):
            while len(st) and arr[st[-1]] < arr[i]:
                nge[st[-1]] = i
                st.pop()   
            st.append(i)
        # print(nge)
        ans = []
        for i in range(n):
            if nge[i]==-1:    # nge[i]==-1, means no future day
                x = 0
            else:
                x = nge[i] - i
            ans.append(x)
        return ans
                