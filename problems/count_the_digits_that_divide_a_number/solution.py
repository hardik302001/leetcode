class Solution:
    def countDigits(self, num: int) -> int:
        ans = 0
        nn = num
        while num>0:
            l = num%10
            num = num//10
            if nn%l==0:
                ans+=1
        return ans