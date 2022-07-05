class Solution:
    def asteroidCollision(self, ast: List[int]) -> List[int]:
        st = []
        n = len(ast)
        for i in range(n):
            if not st:
                st.append(ast[i])
            else:
                if(ast[i]>0):
                    st.append(ast[i])
                else:
                    f = 0
                    while st and st[-1]>0:
                        if st[-1]<abs(ast[i]):
                            st.pop()
                        elif st[-1]==abs(ast[i]):
                            f = 1
                            st.pop()
                            break
                        else:
                            f = 1
                            break
                    if f:continue
                    if (not st) or st[-1]<0: st.append(ast[i])
            # print(st)
        return st