class Solution:
    def strWithout3a3b(self, a: int, b: int) -> str:
        ans = []
        m = min(a,b)
        if m==a:
            for i in range(m):
                ans.append(["b"])
                ans.append(["a"])
            a = a - m
            b = b - m
            if b:
                ans.append(["b"])
                b = b - 1
            i = 0
            while b:
                ans[i].append('b')
                i = i + 2
                b= b - 1
                if i>=len(ans):
                    i = 0
            
        else:
            for i in range(m):
                ans.append(["a"])
                ans.append(["b"])
            a = a - m
            b = b - m
            if a:
                ans.append(["a"])
                a = a - 1
            i = 0
            while a:
                ans[i].append('a')
                i = i + 2
                a = a - 1
                if i>=len(ans):
                    i = 0
        # print(ans)
        res = ""
        for i in range(len(ans)):
            s = "".join(ans[i])
            res = res + s
        return res