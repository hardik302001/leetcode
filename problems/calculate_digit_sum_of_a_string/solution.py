class Solution:
    def digitSum(self, s: str, k: int) -> str:
        ans = 0
        
        while len(s)>k:
            p = []
            for i in range(0 , len(s) , k):
                p.append(s[i:i+k])
            ss =""
            # print(p)
            for i in p:
                su = 0
                for x in i:
                    su+= int(x)
                ss += str(su)
            
            s = ss
        return s