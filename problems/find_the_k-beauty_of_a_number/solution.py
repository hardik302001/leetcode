class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        c = 0
        x = num
        num= str(num)
        n = len(num)
        for i in range(k, n+1):
            p = int(num[i-k:i])
            # print(p)
            if p!=0 and x%p==0:
                c+=1
        return c