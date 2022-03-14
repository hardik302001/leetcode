class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        st = []
        n = len(pushed)
        p = 0
        for i in range(n):
            st.append(pushed[i])
            while st and st[-1]==popped[p]:
                st.pop()
                p+=1
        return p==n
            