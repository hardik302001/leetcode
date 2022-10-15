class Solution:
    def productQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        b = bin(n)[2:]
        pro = [0]
        nos = []
        # print(b)
        for i in range(len(b)-1, -1, -1):
            if(int(b[i])==1):
                nos.append(len(b) - i-1)
       
    
    # expressing power in terms of sum , to take care of it easily
        p = 0
        for i in range(len(nos)):
            p = p + nos[i]
            pro.append(p)
         
        ans = []
        for a , b in queries:
            ans.append(pow(2, pro[b+1] - pro[a], 1000000007))
            

        return ans