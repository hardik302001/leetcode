class Solution:
    def numberOfPairs(self, nums: List[int]) -> List[int]:
        d= Counter()
        for i in nums:
            d[i]+=1
        a = 0
        b = 0
        
        for i in d:
            a+= d[i]//2
            b+=d[i]&1
        return [a, b]