#NSE
#montonic stack

class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        n = len(prices)
        nse = [-1]*n
        st = []
        for i in range(n):
            while st and prices[st[-1]] >= prices[i]:
                nse[st.pop()] = i
            st.append(i)
        ans = []
        # print(nse)
        for i in range(n):
            if nse[i]==-1:
                ans.append(prices[i])
            else:
                ans.append(prices[i] - prices[nse[i]])
        return ans
    