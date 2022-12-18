# lca in a complete binary tree

class Solution:
    def cycleLengthQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        ans = []
        for a, b in queries:            
            c =0
            while a!=b:
                if a>b:
                    a //=2
                    c+=1
                else:
                    b//=2
                    c+=1
                    
            # now a==b , so a is LCA, we will make cycle starting from LCA
            
            ans.append(c+1)   # for the new added edge
        return ans
            
