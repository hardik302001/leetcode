class Solution:
    def multiply(self, n1: str, n2: str) -> str:
        if n1== "0" or n2=="0":
            return "0"
        
        res = [0]*(len(n1) + len(n2))
        n1 = n1[::-1]
        n2 = n2[::-1]
        
        for i1 in range(len(n1)):
            for i2 in range(len(n2)):
                dig = int(n1[i1])*int(n2[i2]) + res[i1 + i2]
                res[i1 + i2] = dig%10
                res[i1 + i2 + 1] += dig//10
        # print(res)
        while res[-1]==0:
            res.pop()
            
        
        res = res[::-1]
    
        ans = ""
        for i in res:
            ans = ans + str(i)
    
        return ans