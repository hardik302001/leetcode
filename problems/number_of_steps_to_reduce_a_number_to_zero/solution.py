class Solution:
    def numberOfSteps(self, num: int) -> int:
        s = bin(num)[2 :]
        print(s)
        ans= len(s)
        ans = ans + s.count('1') -1 #adding count 1 bcz for every time we get 1 we need to do 2 operation, except from when we get 1 for first time
        return ans
        