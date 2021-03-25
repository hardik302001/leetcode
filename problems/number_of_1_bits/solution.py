class Solution:
    def hammingWeight(self, n: int) -> int:
        ans =  bin(n).count("1")
        #converting to bin only takes releveant data
        print(bin(n))
        return ans