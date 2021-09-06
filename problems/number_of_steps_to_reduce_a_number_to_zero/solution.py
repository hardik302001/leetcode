class Solution:
    def numberOfSteps(self, num: int) -> int:
        s = bin(num)[2 :]
        print(s)
        
        ans = 0
        for i in s[::-1]:
            if i=='0':
                ans = ans +1
            else:
                ans = ans + 2
        return ans - 1  #bcz on last step we will have 1, we will make it only 0, we need not totally remove it 